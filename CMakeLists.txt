cmake_minimum_required(VERSION 3.21)

project(solarism)

# SETUP VARIABLES:

# list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/modules)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)
set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIR}")

# add SDL2 paths to C:

set(SDL2_LIB_DIR C:/SDL/lib)
set(SDL2_INCLUDE_DIR C:/SDL/include)
set(SDL2_LIBRARY C:/SDL/bin)

include_directories(
    ${SDL2_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/include
)

link_directories(
    ${SDL2_LIB_DIR}
)

file(GLOB_RECURSE SRC "src/*.cpp" "src/*.h")

message(STATUS "Add source files:")
foreach(SRC_FILE IN LISTS SRC)
    message(STATUS "${SRC_FILE}")
endforeach()
message(STATUS "")

add_executable(${PROJECT_NAME} ${SRC}
        src/Game.cpp
        src/Game.hpp
        src/window.cpp
        src/window.hpp
        src/Planet.cpp
        src/Planet.hpp
        src/Renderer.cpp
        src/Renderer.hpp
        src/units.hpp
        src/Vec.hpp
)

target_link_libraries(
    ${PROJECT_NAME}
        mingw32
        SDL2main
        SDL2
        SDL2_image
)

message(STATUS "Copying all assets to destination folder...")
file(
    COPY assets
    DESTINATION ${OUTPUT_DIR}
)

message(STATUS "Copying all dependencies to destination folder...")
file(GLOB PROJECT_DEPENDENCIES ${SDL2_LIBRARY}/*.dll)

foreach(Dependency IN LISTS PROJECT_DEPENDENCIES)
    file(
        COPY ${Dependency}
        DESTINATION ${OUTPUT_DIR}
    )
endforeach()