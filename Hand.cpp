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
    if(card == nullptr)return;
    if(!IsMouseButtonDown(0)){
        if(game->DropCard(card)){
            hasDropped = true;
            card = nullptr;
        }
    }
}

Hand::Hand(Game* game) {
    this->game = game;
}

bool Hand::HasDropped() {
    bool tmp = hasDropped;
    hasDropped = false;
    return tmp;
}
