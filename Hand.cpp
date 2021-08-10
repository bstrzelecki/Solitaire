#include "Hand.h"

void Hand::Draw() {
    Vector2 mouse = GetMousePosition();
    DrawTexture(*SpriteLoader::GetSprite(card->cardId),
                mouse.x + dragOffset.x, mouse.y + dragOffset.y,
                WHITE);


}
