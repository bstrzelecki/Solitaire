#include "Hand.h"

void Hand::Draw() {
    Vector2 mouse = GetMousePosition();
    if(card == nullptr) return;
    DrawTexture(*SpriteLoader::GetSprite(card->GetCardId()),
                mouse.x - dragOffset.x, mouse.y - dragOffset.y,
                WHITE);


}

void Hand::PickCard(Card *card, Vector2 offset) {
    this->card = card;
    dragOffset = offset;
}

void Hand::Update() {
    if(hasDropped)hasDropped = false;
    if(card == nullptr)return;
    if(!IsMouseButtonDown(0)){
        if(first == nullptr){
            if(game->DropCard(card)){
                hasDropped = true;
                card = nullptr;
            }
        }else{
            if(game->DropRange(first, card)){
                hasDropped = true;
                card = nullptr;
                first = nullptr;
            }
        }
    }

}

Hand::Hand(Game* game) {
    this->game = game;
}

bool Hand::HasDropped() {
    return hasDropped;
}

void Hand::PickCard(Card* start, Card* end, Vector2 offset) {
    first = start;
    card = end;
}
