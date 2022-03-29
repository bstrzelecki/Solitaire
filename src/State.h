#pragma once

#include "classes.fwd"
#include <memory>
#include "Game.h"

namespace State{
    std::shared_ptr<Game> GetState();
    void InitializeState();
}