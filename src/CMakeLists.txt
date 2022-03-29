cmake_minimum_required(VERSION 3.21)
project(Solitaire)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib 4.0.0 QUIET)

if (NOT raylib_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) 
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()



set(BINARY ${CMAKE_PROJECT_NAME})
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})
add_executable(${BINARY} ${SOURCES})
add_library(${BINARY}_lib STATIC ${SOURCES})
target_include_directories(${BINARY}_lib PUBLIC .)
#add_executable(Solitaire main.cpp Card.cpp Card.h State.h CardDefinitions.h SpriteLoader.h Column.cpp Column.h SpriteLoader.cpp Deck.cpp Deck.h Hand.cpp Hand.h Game.cpp Game.h classes.fwd State.cpp Stack.cpp Stack.h)
target_link_libraries(${PROJECT_NAME} raylib)
target_link_libraries(${BINARY}_lib raylib)


file(COPY Sprites DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
