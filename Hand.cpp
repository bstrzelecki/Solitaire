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
