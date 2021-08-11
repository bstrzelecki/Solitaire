
#include "Game.h"



Game::Game() : deck(&hand, 0,0),columns{0,
                                        (SpriteLoader::GetSprite(NONE)->width + offset),
                                        (SpriteLoader::GetSprite(NONE)->width + offset)*2,
                                        (SpriteLoader::GetSprite(NONE)->width + offset)*3,
                                        (SpriteLoader::GetSprite(NONE)->width + offset)*4,
                                        (SpriteLoader::GetSprite(NONE)->width + offset)*5,
                                        (SpriteLoader::GetSprite(NONE)->width + offset)*6} {


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



    for(int i = 28; i < 52; i++){
        deck.Add(new Card(cards[i]));
    }

}

void Game::Start() {
    while (!WindowShouldClose()){
        BeginDrawing();

        ClearBackground(DARKGREEN);

        for (Column col:columns) {
            col.Draw();
        }

        deck.Update();
        deck.Draw();

        hand.Draw();

        EndDrawing();
    }
}

Game::~Game() {
    CloseWindow();
}
