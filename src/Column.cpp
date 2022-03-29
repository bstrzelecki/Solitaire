#include "Column.h"

bool Column::isDragging;

Column::Column(int x) {
    Texture2D* sample = SpriteLoader::GetSprite(NONE);
    size = {static_cast<float>(x),
            static_cast<float>(sample->height) + 10,
            static_cast<float>(sample->width),
            static_cast<float>(GetScreenHeight())};
    isDragging = false;
}

bool Column::IsPlaceableColor(int cardId) const{
    if(cards == nullptr) [[unlikely]] {
        return (cardId & RANK_MASK)==KING;
    }
    if(((cardId>>2)-(cards->GetCardId()>>2) == -1)){
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
    if(isDragging)return;
    if(cards!= nullptr){
        cards->Show();
    }
}

Rectangle Column::GetSize() const{
    return size;
}

void Column::Update() {
    Vector2 mouse = GetMousePosition();
    Hand& hand = State::GetState()->GetHand();
    if(cards!=nullptr &&CheckCollisionPointRec(mouse, size) && IsMouseButtonDown(0) && !isDragging){
        isDragging = true;
        start = cards;
        Card* next = cards;
        if(!CheckCollisionPointRec(mouse, cards->rect)){
            while(next->nextInStack != nullptr && next->nextInStack->IsVisible()){
                if(CheckCollisionPointRec(mouse, next->rect)){
                    break;
                }
                next = next->nextInStack;
            }
        }else{
            hand.PickCard(next, {mouse.x - next->rect.x, mouse.y - next->rect.y});
            end = next;
            start = nullptr;
            cards = next->nextInStack;
            next->nextInStack = nullptr;
            return;
        }
        if(CheckCollisionPointRec(mouse, next->rect)){
            hand.PickCard(cards, next, {mouse.x - next->rect.x, mouse.y - next->rect.y});
            cards = next->nextInStack;
            end = next;
            next->nextInStack = nullptr;
        }
    }

    if(end != nullptr&& !IsMouseButtonDown(0)){
        hand.PickCard(nullptr, {0,0});
        if(!hand.HasDropped()){
            end->nextInStack = cards;
            if(start == nullptr)
                cards = end;
            else
                cards = start;
        }
        isDragging = false;
        end = nullptr;
        start = nullptr;
    }
    if(isDragging && !IsMouseButtonDown(0)){
        isDragging = false;
        end = nullptr;
        start = nullptr;
    }


    ShowFirstCard();
}
