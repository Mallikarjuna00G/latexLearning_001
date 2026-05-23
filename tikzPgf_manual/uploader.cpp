#include <cstdio>
#include <curl/curl.h>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

using json = nlohmann::json;

// Global callback to handle network response capturing
size_t NetworkWriteCallback(void *contents, size_t size, size_t nmemb,
                            std::string *userp) {
  userp->append((char *)contents, size * nmemb);
  return size * nmemb;
}

// 1. Exchange the refresh token for a volatile, short-lived Access Token
std::string FetchAccessToken(const std::string &client_id,
                             const std::string &client_secret,
                             const std::string &refresh_token) {
  CURL *curl = curl_easy_init();
  std::string response;

  if (curl) {
    std::string url = "https://oauth2.googleapis.com/token";
    std::string payload =
        "client_id=" + client_id + "&client_secret=" + client_secret +
        "&refresh_token=" + refresh_token + "&grant_type=refresh_token";

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NetworkWriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
  }

  auto parsed_json = json::parse(response);
  return parsed_json["access_token"].get<std::string>();
}

// 2. Add video to a YouTube playlist
void AddVideoToPlaylist(const std::string &token,
                        const std::string &playlist_id,
                        const std::string &video_id) {
  CURL *curl = curl_easy_init();
  if (!curl)
    return;

  std::string url = "https://www.googleapis.com/youtube/v3/playlistItems?part=snippet";

  struct curl_slist *headers = nullptr;
  headers = curl_slist_append(headers, ("Authorization: Bearer " + token).c_str());
  headers = curl_slist_append(headers, "Content-Type: application/json; charset=UTF-8");

  json body = {
      {"snippet", {
          {"playlistId", playlist_id},
          {"resourceId", {
              {"kind", "youtube#video"},
              {"videoId", video_id}
          }}
      }}
  };
  std::string payload = body.dump();

  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());

  std::string response;
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NetworkWriteCallback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

  std::cout << "Adding video to playlist: " << playlist_id << "...\n";
  CURLcode result = curl_easy_perform(curl);

  if (result == CURLE_OK) {
    auto response_json = json::parse(response);
    if (response_json.contains("id")) {
      std::cout << "Successfully added video to playlist. (PlaylistItem ID: "
                << response_json["id"].get<std::string>() << ")\n";
    } else {
      std::cerr << "YouTube Playlist API Error: " << response << "\n";
    }
  } else {
    std::cerr << "Playlist network error: " << curl_easy_strerror(result) << "\n";
  }

  curl_slist_free_all(headers);
  curl_easy_cleanup(curl);
}

// Helper function to check if video is a Short based on resolution (vertical/square aspect ratio)
bool IsShortVideo(const std::string &video_path) {
  std::string command = "ffprobe -v error -select_streams v:0 -show_entries stream=width,height -of csv=s=x:p=0 \"" + video_path + "\"";
  FILE *pipe = popen(command.c_str(), "r");
  if (!pipe) {
    return false;
  }
  char buffer[128];
  std::string result = "";
  while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
    result += buffer;
  }
  pclose(pipe);

  // Parse result of format "widthxheight\n"
  size_t x_pos = result.find('x');
  if (x_pos != std::string::npos) {
    try {
      int width = std::stoi(result.substr(0, x_pos));
      int height = std::stoi(result.substr(x_pos + 1));
      return height >= width; // Vertical or square is a Short
    } catch (...) {
      // Ignore parsing errors
    }
  }
  return false;
}

// 3. Execute the multipart REST upload
std::string ExecuteVideoUpload(const std::string &token, const std::string &video_path,
                               const json &metadata) {
  CURL *curl = curl_easy_init();
  std::string video_id = "";
  if (!curl)
    return video_id;

  std::string url = "https://www.googleapis.com/upload/youtube/v3/"
                    "videos?uploadType=multipart&part=snippet,status";
  if (metadata.contains("paidProductPlacementDetails")) {
    url += ",paidProductPlacementDetails";
  }

  struct curl_slist *headers = nullptr;
  headers =
      curl_slist_append(headers, ("Authorization: Bearer " + token).c_str());
  headers = curl_slist_append(
      headers,
      "Content-Type: multipart/related; boundary=boundary_layer_delimiter");

  // Construct valid API payload using only supported keys
  json api_payload = {
      {"snippet", metadata["snippet"]},
      {"status", metadata["status"]}
  };
  if (metadata.contains("paidProductPlacementDetails")) {
    api_payload["paidProductPlacementDetails"] = metadata["paidProductPlacementDetails"];
  }

  // Construct MIME multipart container
  std::string payload_body =
      "--boundary_layer_delimiter\r\n"
      "Content-Type: application/json; charset=UTF-8\r\n\r\n" +
      api_payload.dump() +
      "\r\n"
      "--boundary_layer_delimiter\r\n"
      "Content-Type: video/mp4\r\n\r\n";

  // Stream binary video blocks directly into the transmission string
  std::ifstream binary_stream(video_path, std::ios::binary);
  if (!binary_stream.is_open()) {
    std::cerr << "Fatal: Target video file could not be mapped.\n";
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
    return video_id;
  }
  std::string binary_buffer((std::istreambuf_iterator<char>(binary_stream)),
                            std::istreambuf_iterator<char>());
  payload_body += binary_buffer + "\r\n--boundary_layer_delimiter--\r\n";

  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload_body.c_str());
  curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE_LARGE,
                   (curl_off_t)payload_body.size());

  std::string server_response;
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NetworkWriteCallback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &server_response);

  std::cout << "Streaming video stream packets to Google target ingestion "
               "servers...\n";
  CURLcode result = curl_easy_perform(curl);

  if (result == CURLE_OK) {
    auto response_json = json::parse(server_response);
    if (response_json.contains("id")) {
      video_id = response_json["id"].get<std::string>();
      std::cout << "\n=========================================\n";
      std::cout << "UPLOAD SUCCESSFUL!\n";
      std::cout << "Video ID: " << video_id << "\n";
      if (IsShortVideo(video_path)) {
        std::cout << "URL: https://youtube.com/shorts/" << video_id << "\n";
      } else {
        std::cout << "URL: https://youtu.be/" << video_id << "\n";
      }
      std::cout << "=========================================\n";
    } else {
      std::cerr << "API Error Response: " << server_response << "\n";
    }
  } else {
    std::cerr << "Transport failure: " << curl_easy_strerror(result) << "\n";
  }

  curl_slist_free_all(headers);
  curl_easy_cleanup(curl);
  return video_id;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " <path_to_video.mp4> [path_to_metadata.json]\n";
    return 1;
  }
  std::string target_video = argv[1];

  // Resolve metadata
  std::string video_metadata_path =
      (argc >= 3) ? argv[2] : "video_metadata.json";
  std::ifstream video_metadata_file(video_metadata_path);
  if (!video_metadata_file.is_open()) {
    std::cerr << "Fatal: metadata not found!" << std::endl;
    return 1;
  }
  json video_metadata = json::parse(video_metadata_file);

  // Validate metadata fields (limits)
  if (video_metadata.contains("snippet")) {
    auto &snippet = video_metadata["snippet"];

    if (snippet.contains("title")) {
      std::string title = snippet["title"].get<std::string>();
      if (title.length() > 100) {
        std::cerr << "Fatal: Title length (" << title.length() 
                  << ") exceeds the limit of 100 characters. Stopping execution." << std::endl;
        return 1;
      }
    }
    if (snippet.contains("description")) {
      std::string desc = snippet["description"].get<std::string>();
      if (desc.length() > 5000) {
        std::cerr << "Fatal: Description length (" << desc.length() 
                  << ") exceeds the limit of 5000 characters. Stopping execution." << std::endl;
        return 1;
      }
    }
    if (snippet.contains("tags")) {
      auto &tags = snippet["tags"];
      if (tags.is_array()) {
        size_t total_tags_length = 0;
        for (auto &tag : tags) {
          if (tag.is_string()) {
            total_tags_length += tag.get<std::string>().length() + 1;
          }
        }
        if (total_tags_length > 500) {
          std::cerr << "Fatal: Tags total length (" << total_tags_length 
                    << ") exceeds the limit of 500 characters. Stopping execution." << std::endl;
          return 1;
        }
      }
    }
  }

  // Handle related video info warning
  if (video_metadata.contains("relatedVideoId") && !video_metadata["relatedVideoId"].get<std::string>().empty()) {
    std::cout << "\n[Info] A related video ID was specified: " 
              << video_metadata["relatedVideoId"].get<std::string>() 
              << "\nNote: Linking a related video to a Short must be done manually in YouTube Studio, as the public YouTube Data API v3 does not support this feature.\n";
  }

  // Load your combined secret file
  std::ifstream config_file("client_secrets.json");
  if (!config_file.is_open()) {
    std::cerr << "Fatal: client_secrets.json missing.\n";
    return 1;
  }

  // Dig into the "installed" block
  auto file_root = json::parse(config_file);
  auto credentials = file_root["installed"];

  curl_global_init(CURL_GLOBAL_ALL);

  std::cout << "Requesting fresh ephemeral session handshake...\n";
  std::string access_token =
      FetchAccessToken(credentials["client_id"], credentials["client_secret"],
                       credentials["refresh_token"]);

  std::string video_id = ExecuteVideoUpload(access_token, target_video, video_metadata);

  if (!video_id.empty() && video_metadata.contains("playlistId")) {
    std::string playlist_id = video_metadata["playlistId"].get<std::string>();
    if (!playlist_id.empty()) {
      AddVideoToPlaylist(access_token, playlist_id, video_id);
    }
  }

  curl_global_cleanup();
  return 0;
}