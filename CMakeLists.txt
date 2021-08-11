cmake_minimum_required(VERSION 3.21)
project(Solitaire)

set(CMAKE_CXX_STANDARD 20)

add_executable(Solitaire main.cpp Card.cpp Card.h State.h CardDefinitions.h Point.h SpriteLoader.h Column.cpp Column.h SpriteLoader.cpp Deck.cpp Deck.h Hand.cpp Hand.h Game.cpp Game.h classes.fwd)
target_link_libraries(Solitaire "/usr/lib/libraylib.so")