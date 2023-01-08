cmake_minimum_required(VERSION 3.12)
project(MyMsg)
set(CMAKE_CX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

#find_package(nlohmann REQUIRED)

# use fetchcontent to download and install dependencies
include(FetchContent)
# #add_subdirectory(lib/nlohmann)
# add dependency
FetchContent_Declare(
    boost 
    GIT_REPOSITORY http://github.com/boostorg/boost.git 
    GIT_TAG boost-1.81.0
)
FetchContent_MakeAvailable(boost)

# nlohmann json
FetchContent_Declare(
  nlohmann_json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.10.5
)
FetchContent_MakeAvailable(nlohmann_json)

# fmt

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG        9.1.0
)
FetchContent_MakeAvailable(fmt)

#find_package(Boost REQUIRED COMPONENTS system thread)

# add src and include directories to project
#add_subdirectory(src)
include_directories(include)

# Build executable
add_executable(MyMsg src/main.cpp)

target_link_libraries(MyMsg Boost::asio fmt::fmt nlohmann_json::nlohmann_json)

message("")
message("configuration:        ${CMAKE_BUILD_TYPE}")
message("will be built in:     ${CMAKE_BINARY_DIR}")
message("CMAKE_C_COMPILER:     ${CMAKE_C_COMPILER}")
message("CMAKE_CXX_COMPILER:   ${CMAKE_CXX_COMPILER}")
message("will be installed in: ${CMAKE_INSTALL_PREFIX}")
message("\n")