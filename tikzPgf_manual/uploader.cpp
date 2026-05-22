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

// 2. Execute the multipart REST upload
void ExecuteVideoUpload(const std::string &token,
                        const std::string &video_path) {
  CURL *curl = curl_easy_init();
  if (!curl)
    return;

  std::string url = "https://www.googleapis.com/upload/youtube/v3/"
                    "videos?uploadType=multipart&part=snippet,status";

  struct curl_slist *headers = nullptr;
  headers =
      curl_slist_append(headers, ("Authorization: Bearer " + token).c_str());
  headers = curl_slist_append(
      headers,
      "Content-Type: multipart/related; boundary=boundary_layer_delimiter");

  // Define metadata payload
  json metadata = {{"snippet",
                    {
                        {"title", "Automated Demonstration"},
                        {"description", "This asset was pushed via custom "
                                        "systems-level C++ network routines."},
                        {"tags", json::array({"tikz", "latex", "automation"})},
                        {"categoryId", "28"} // Science & Technology ID
                    }},
                   {"status",
                    {
                        {"privacyStatus", "private"}
                        // Safest default for testing automated pipelines
                    }}};

  // Construct MIME multipart container
  std::string payload_body =
      "--boundary_layer_delimiter\r\n"
      "Content-Type: application/json; charset=UTF-8\r\n\r\n" +
      metadata.dump() +
      "\r\n"
      "--boundary_layer_delimiter\r\n"
      "Content-Type: video/mp4\r\n\r\n";

  // Stream binary video blocks directly into the transmission string
  std::ifstream binary_stream(video_path, std::ios::binary);
  if (!binary_stream.is_open()) {
    std::cerr << "Fatal: Target video file could not be mapped.\n";
    return;
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
      std::cout << "\n=========================================\n";
      std::cout << "UPLOAD SUCCESSFUL!\n";
      std::cout << "Video ID: " << response_json["id"].get<std::string>()
                << "\n";
      std::cout << "URL: https://youtu.be/"
                << response_json["id"].get<std::string>() << "\n";
      std::cout << "=========================================\n";
    } else {
      std::cerr << "API Error Response: " << server_response << "\n";
    }
  } else {
    std::cerr << "Transport failure: " << curl_easy_strerror(result) << "\n";
  }

  curl_slist_free_all(headers);
  curl_easy_cleanup(curl);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " <path_to_video.mp4>\n";
    return 1;
  }
  std::string target_video = argv[1];

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

  ExecuteVideoUpload(access_token, target_video);

  curl_global_cleanup();
  return 0;
}