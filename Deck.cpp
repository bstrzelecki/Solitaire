#include "Deck.h"

Deck::Deck(int x, int y) {
    backSprite = SpriteLoader::GetSprite(BACK);
    position = {static_cast<float>(x),
                static_cast<float>(y),
                static_cast<float>(backSprite->width),
                static_cast<float>(backSprite->height)};

}

void Deck::Draw() {
    if(!hidden.empty())
        DrawTexture(*backSprite, position.x, position.y, WHITE);
    if(!visible.empty())
        DrawTexture(*SpriteLoader::GetSprite(visible.back()->cardId),
                    position.x + position.width + 5, position.y,
                    WHITE);

}

void Deck::Update() {
    Vector2 mouse = GetMousePosition();
    if(mouse.x > position.x && mouse.x < position.x + position.width
    && mouse.y > position.y && mouse.y < position.y + position.height && IsMouseButtonPressed(0)){
        next();
    }
}

void Deck::next() {
    if(!hidden.empty()){
        visible.push(hidden.top());
        hidden.pop();
    }else{
        while(!visible.empty()){
            hidden.push(visible.front());
            visible.pop();
        }
    }
}

void Deck::Add(Card *card) {
    hidden.push(card);
}
