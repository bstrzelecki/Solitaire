cmake_minimum_required(VERSION 3.21)
project(Solitaire)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib 4.0.0 QUIET)

if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()


add_executable(Solitaire main.cpp Card.cpp Card.h State.h CardDefinitions.h SpriteLoader.h Column.cpp Column.h SpriteLoader.cpp Deck.cpp Deck.h Hand.cpp Hand.h Game.cpp Game.h classes.fwd State.cpp Stack.cpp Stack.h)
target_link_libraries(${PROJECT_NAME} raylib)


file(COPY Sprites DESTINATION ${CMAKE_BINARY_DIR})