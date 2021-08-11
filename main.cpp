#include "SpriteLoader.h"
#include "Game.h"

int main()
{

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Solitaire");

    SetTargetFPS(144);

    SpriteLoader::LoadSprites();

    Game game;
    game.Start();

    return 0;
}