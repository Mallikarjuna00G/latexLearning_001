#include <cstring>
#include <curl/curl.h>
#include <fstream>
#include <iostream>
#include <netinet/in.h>
#include <nlohmann/json.hpp>
#include <string>
#include <sys/socket.h>
#include <unistd.h>

using json = nlohmann::json;

// Helper to handle libcurl response string storage
size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                     std::string *userp) {
  userp->append((char *)contents, size * nmemb);
  return size * nmemb;
}

// Minimal HTTP server to capture the authorization code from the browser
// redirect
std::string listenForCode() {
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  int opt = 1;
  setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

  struct sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(8080); // Listening on http://localhost:8080

  bind(server_fd, (struct sockaddr *)&address, sizeof(address));
  listen(server_fd, 1);

  std::cout << "Waiting for browser authentication response on port 8080...\n";
  int new_socket = accept(server_fd, nullptr, nullptr);

  char buffer[1024] = {0};
  read(new_socket, buffer, 1024);

  // Send a success message back to the browser tab
  std::string httpResponse =
      "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"
      "<html><body><h2>Authentication successful! You can close this tab and "
      "return to the terminal.</h2></body></html>";
  write(new_socket, httpResponse.c_str(), httpResponse.length());

  close(new_socket);
  close(server_fd);

  // Extract code from HTTP GET request: "GET /?code=4/0Af... HTTP/1.1"
  std::string request(buffer);
  size_t pos = request.find("code=");
  if (pos == std::string::npos)
    return "";

  size_t end_pos = request.find(" ", pos);
  return request.substr(pos + 5, end_pos - (pos + 5));
}

int main() {
  // 1. Read your client_secrets.json
  std::ifstream f("client_secrets.json");
  if (!f.is_open()) {
    std::cerr << "Error: client_secrets.json not found!\n";
    return 1;
  }
  json secrets = json::parse(f)["installed"];
  std::string client_id = secrets["client_id"];
  std::string client_secret = secrets["client_secret"];

  // 2. Construct the Google OAuth authorization URL
  std::string redirect_uri = "http://localhost:8080";
  std::string scope = "https://www.googleapis.com/auth/youtube.upload";
  std::string auth_url = "https://accounts.google.com/o/oauth2/v2/auth?"
                         "client_id=" +
                         client_id + "&redirect_uri=" + redirect_uri +
                         "&response_type=code" + "&scope=" + scope +
                         "&access_type=offline" + // "offline" guarantees a
                                                  // refresh token is returned
                         "&prompt=consent";

  // 3. Open the user's default browser natively via Linux system call
  std::cout << "Opening browser for authentication...\n";
  std::string command = "xdg-open \"" + auth_url + "\"";
  if (system(command.c_str()) != 0) {
    std::cout << "Failed to open browser automatically. Please open this link "
                 "manually:\n"
              << auth_url << "\n";
  }

  // 4. Block and listen on port 8080 for the redirected auth code
  std::string auth_code = listenForCode();
  if (auth_code.empty()) {
    std::cerr << "Failed to capture authentication code.\n";
    return 1;
  }

  // 5. Exchange the authentication code for the permanent Refresh Token via
  // libcurl
  curl_global_init(CURL_GLOBAL_ALL);
  CURL *curl = curl_easy_init();
  std::string response_string;

  if (curl) {
    std::string token_url = "https://oauth2.googleapis.com/token";
    std::string post_fields = "code=" + auth_code + "&client_id=" + client_id +
                              "&client_secret=" + client_secret +
                              "&redirect_uri=" + redirect_uri +
                              "&grant_type=authorization_code";

    curl_easy_setopt(curl, CURLOPT_URL, token_url.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_fields.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);

    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();

  // 6. Output the final tokens
  try {
    auto response_json = json::parse(response_string);
    std::cout << "\n==================================================\n";
    std::cout << "SUCCESS! TARGET ACQUIRED.\n";
    std::cout << "Refresh Token: "
              << response_json["refresh_token"].get<std::string>() << "\n";
    std::cout << "==================================================\n";
  } catch (...) {
    std::cerr << "Error parsing Google token response: " << response_string
              << "\n";
  }

  return 0;
}