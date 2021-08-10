#include "Card.h"

void Card::Draw() {

    int offset = 0;
    Card* next = nextInStack;

    while(next != nullptr){
        offset += 30;
        next = nextInStack->nextInStack;
    }

    DrawTexture((IsVisible()?(*sprite):*SpriteLoader::GetSprite(BACK)), rect.x, rect.y, WHITE);
}

Card::Card(int cardId) {
    sprite = SpriteLoader::GetSprite(cardId);
    this->cardId = cardId;
    rect = Rectangle{0,0, static_cast<float>(sprite->width), static_cast<float>(sprite->height)};
}

void Card::Update() {

}

bool Card::IsVisible() {
    return isVisible;
}

void Card::Show() {
    isVisible = true;
}

