#pragma once

struct State{
    int deltaTime = 0;
    int flagBuffer = 0;

    State(int deltaTime){
        this->deltaTime = deltaTime;
    }
};