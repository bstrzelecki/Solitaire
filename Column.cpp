#include "Column.h"

Column::Column(int x) {
    Texture2D* sample = SpriteLoader::GetSprite(NONE);
    size = {static_cast<float>(x),
            static_cast<float>(sample->height) + 10,
            static_cast<float>(sample->width),
            static_cast<float>(GetScreenHeight())};

}

bool Column::IsPlaceableColor(int cardId) const{
    if(cards == nullptr) [[unlikely]] {
        return (cardId & RANK_MASK)==KING;
    }
    if(((cardId>>2)<(cards->GetCardId()>>2))){
        return ((cards->GetCardId() & COLOR_MASK)==SPADE || (cards->GetCardId() & COLOR_MASK)==CLUB)?
        ((cardId & COLOR_MASK)==HEART || (cardId & COLOR_MASK)==DIAMOND):
        ((cardId & COLOR_MASK)==SPADE || (cardId & COLOR_MASK)==CLUB);
    }
    return false;
}

void Column::Draw() const{
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

Rectangle Column::GetSize() const{
    return size;
}

void Column::Update() {
    ShowFirstCard();
}
