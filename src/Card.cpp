#include "Card.h"

void Card::Draw() {
    DrawTexture((IsVisible()?(*sprite):*SpriteLoader::GetSprite(BACK)), rect.x, rect.y, WHITE);
}

Card::Card(int cardId) {
    sprite = SpriteLoader::GetSprite(cardId);
    this->cardId = cardId;
    rect = Rectangle{0,0, static_cast<float>(sprite->width), static_cast<float>(sprite->height)};
}

bool Card::IsVisible() {
    return isVisible;
}

void Card::Show() {
    isVisible = true;
}

int Card::GetCardId() const {
    if(cardId>=0&& cardId <= (KING|DIAMOND)){
        return cardId;
    }else{
        return NONE;
    }
}

