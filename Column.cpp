#include "Column.h"

Column::Column(int x) {
    Texture2D* sample = SpriteLoader::GetSprite(NONE);
    size = {static_cast<float>(x),
            static_cast<float>(sample->height) + 10,
            static_cast<float>(sample->width),
            static_cast<float>(GetScreenHeight())};

}

bool Column::IsPlaceableColor(int cardId) {
    if(cards == nullptr) [[unlikely]] {
        return cardId & KING;
    }
    if(((cardId>>2)<(cards->cardId>>2))){
        return cards->cardId & SPADE || cards->cardId & CLUB?
        (cardId & HEART || cardId & DIAMOND):
        (cardId & SPADE || cardId & CLUB);
    }
    return false;
}

void Column::Draw() {
    std::stack<Card*> tmp;

    Card* next = cards;
    while(next != nullptr){
        tmp.push(next);
        next = next->nextInStack;
    }
    while(!tmp.empty()){
        tmp.top()->Draw();
        tmp.pop();
    }
}

void Column::AddCard(Card *card) {
    card->rect.x = size.x;

    card->rect.y = cards != nullptr?cards->rect.y + 30: size.y;

    card->nextInStack = cards;
    cards = card;
}

void Column::ShowFirstCard() {
    if(cards!= nullptr){
        cards->Show();
    }
}
