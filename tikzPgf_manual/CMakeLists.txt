cmake_minimum_required(VERSION 3.12)
project(tikz_youtube_uploader CXX)

# Require C++17 as specified in standard compilation commands
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required libraries
find_package(CURL REQUIRED)
find_package(nlohmann_json REQUIRED)

# Default target for uploader.cpp
add_executable(uploader uploader.cpp)
target_link_libraries(uploader PRIVATE CURL::libcurl nlohmann_json::nlohmann_json)
set_target_properties(uploader PROPERTIES OUTPUT_NAME "yt_upload.out")

# Non-default target for get_refresh_token.cpp (excluded from default 'all' build)
add_executable(get_refresh_token EXCLUDE_FROM_ALL get_refresh_token.cpp)
target_link_libraries(get_refresh_token PRIVATE CURL::libcurl nlohmann_json::nlohmann_json)
set_target_properties(get_refresh_token PROPERTIES OUTPUT_NAME "get_token.out")
