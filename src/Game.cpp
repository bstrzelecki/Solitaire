
#include "Game.h"



Game::Game() : hand(this), deck(&hand, 0,0),columns{0,
                                        (SpriteLoader::GetSprite(NONE)->width + offset),
                                        (SpriteLoader::GetSprite(NONE)->width + offset)*2,
                                        (SpriteLoader::GetSprite(NONE)->width + offset)*3,
                                        (SpriteLoader::GetSprite(NONE)->width + offset)*4,
                                        (SpriteLoader::GetSprite(NONE)->width + offset)*5,
                                        (SpriteLoader::GetSprite(NONE)->width + offset)*6},
                                        stacks{(SpriteLoader::GetSprite(NONE)->width + offset)*3,
                                               (SpriteLoader::GetSprite(NONE)->width + offset)*4,
                                               (SpriteLoader::GetSprite(NONE)->width + offset)*5,
                                               (SpriteLoader::GetSprite(NONE)->width + offset)*6,}{


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

        hand.Update();


        for(int i = 0; i<7; i++){
            columns[i].Update();
            columns[i].Draw();
        }

        for(int i = 0; i < 4; i++){
            stacks[i].Draw();
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

bool Game::DropCard(Card *card) {
    Vector2 mouse = GetMousePosition();
    for(int i = 0; i < 4; i++){
        if(CheckCollisionPointRec(mouse, stacks[i].GetSize())){
            return stacks[i].Drop(card);
        }
    }
    for (int i = 0; i < 7; i++) {
        if(mouse.x < columns[i].GetSize().x || mouse.x > columns[i].GetSize().x + columns[i].GetSize().width) continue;
        if(columns[i].IsPlaceableColor(card->GetCardId())){
            columns[i].AddCard(card);
            columns[i].ShowFirstCard();
            return true;
        }
    }
    return false;
}

Hand& Game::GetHand() {
    return hand;
}

bool Game::DropRange(Card* start, Card* end) {
    Vector2 mouse = GetMousePosition();
    for (int i = 0; i < 7; i++) {
        if(mouse.x < columns[i].GetSize().x || mouse.x > columns[i].GetSize().x + columns[i].GetSize().width) continue;
        if(columns[i].IsPlaceableColor(end->GetCardId())){
            columns[i].AddCard(end);

            std::stack<Card*> tmp;
            Card* next = start;
            while(next != end){
                tmp.push(next);
                next = next->nextInStack;
            }
            while(!tmp.empty()){
                columns[i].AddCard(tmp.top());
                tmp.pop();
            }


            return true;
        }
    }
    return false;
}
