#include <memory>
#include "SpriteLoader.h"
#include "Game.h"

int main()
{

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Solitaire");

    SetTargetFPS(144);

    SpriteLoader::LoadSprites();

    State::InitializeState();

    State::GetState()->Start();

    return 0;
}