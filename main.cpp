#include "raylib.h"

#include "SpriteLoader.h"
#include "Column.h"
#include "Deck.h"
#include <array>
#include <vector>
#include <random>

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Solitaire");

    SetTargetFPS(144);

    SpriteLoader::LoadSprites();

    Texture2D* sample = SpriteLoader::GetSprite(NONE);

    int offset = 5;

    std::array<Column, 7> columns{0,
                                  (sample->width + offset),
                                  (sample->width + offset)*2,
                                  (sample->width + offset)*3,
                                  (sample->width + offset)*4,
                                  (sample->width + offset)*5,
                                  (sample->width + offset)*6};

    std::vector<int> cards(52);
    for(int i = 0; i < 52;i++){
        cards[i] = i;
    }

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(cards.begin(), cards.end(), g);

    int c = 0;
    int s = 1;
    int sc = 0;
    for(int i = 0; i < 28;i++){
        columns[c].AddCard(new Card(cards[i]));
        sc++;
        if(sc==s){
            c++;
            if(c == 7)break;
            s++;
            sc = 0;
        }
    }

    for (Column col:columns) {
        col.ShowFirstCard();
    }

    Deck deck(0,0);

    for(int i = 28; i < 52; i++){
        deck.Add(new Card(cards[i]));
    }

    while (!WindowShouldClose()){
        BeginDrawing();

        ClearBackground(DARKGREEN);

        for (Column col:columns) {
            col.Draw();
        }

        deck.Update();
        deck.Draw();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}