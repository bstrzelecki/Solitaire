#include "Deck.h"

Deck::Deck(Hand* hand, int x, int y) {
    backSprite = SpriteLoader::GetSprite(BACK);
    position = {static_cast<float>(x),
                static_cast<float>(y),
                static_cast<float>(backSprite->width),
                static_cast<float>(backSprite->height)};
    this->hand = hand;
}

void Deck::Draw() {
    if(!hidden.empty())
        DrawTexture(*backSprite, position.x, position.y, WHITE);
    if(!visible.empty())
        DrawTexture(*SpriteLoader::GetSprite(visible.back()->GetCardId()),
                    position.x + position.width + 5, position.y,
                    WHITE);

}

void Deck::Update() {
    Vector2 mouse = GetMousePosition();
    if(dragged != nullptr && !IsMouseButtonDown(0)){
        hand->PickCard(nullptr, {0,0});
        visible.push_back(dragged);
        dragged = nullptr;
    }
    if(mouse.x > position.x && mouse.x < position.x + position.width
    && mouse.y > position.y && mouse.y < position.y + position.height && IsMouseButtonPressed(0)){
        next();
    }

    if(mouse.x > position.x + position.width + 5 && mouse.x < position.x + position.width * 2 + 5
    && mouse.y > position.y && mouse.y < position.y + position.height && IsMouseButtonPressed(0)){
        hand->PickCard(visible.back(), {mouse.x - (position.x + position.width + 5), mouse.y - position.y});
        dragged = visible.back();
        visible.pop_back();
    }

}

void Deck::next() {
    if(!hidden.empty()){
        visible.push_back(hidden.top());
        hidden.pop();
    }else{
        while(!visible.empty()){
            hidden.push(visible.back());
            visible.pop_back();
        }
    }
}

void Deck::Add(Card *card) {
    hidden.push(card);
}
