cmake_minimum_required(VERSION 3.12)
project(MyMsg)
set(CMAKE_CX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

#find_package(nlohmann REQUIRED)

# use fetchcontent to download and install dependencies
# include(FetchContent)
# #add_subdirectory(lib/nlohmann)
# # add dependency
# FetchContent_Declare(
#     boost 
#     GIT_REPOSITORY http://github.com/boostorg/boost.git 
#     GIT_TAG boost-1.81.0
# )
#FetchContent_MakeAvailable(boost)
find_package(Boost REQUIRED COMPONENTS system thread)

# add src and include directories to project
#add_subdirectory(src)
include_directories(include)

# Build executable
add_executable(MyMsg src/main.cpp)

target_link_libraries(MyMsg Boost::system)