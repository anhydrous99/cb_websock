cmake_minimum_required(VERSION 3.5.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")
project(cb_websock)
set(requiredlibs)

find_package(Threads REQUIRED)
set(requiredlibs ${requiredlibs} ${CMAKE_THREAD_LIBS_INIT})

find_package(rapidjson REQUIRED)
include_directories(${RAPIDJSON_INCLUDE_DIRS})

find_package(Casablanca REQUIRED)
include_directories(${CASABLANCA_INCLUDE_DIR})
set(requiredlibs ${requiredlibs} ${CASABLANCA_LIBRARIES})

include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(cb_websock ${SOURCES})

target_link_libraries(cb_websock ${requiredlibs})
