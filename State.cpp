#include "State.h"

namespace State{
    std::shared_ptr<Game> game;
}

std::shared_ptr<Game> State::GetState() {
    if(game == nullptr) InitializeState();
    return game;
}

void State::InitializeState() {
    game = std::make_shared<Game>();
}