#include "Stack.h"

Stack::Stack(int x) {
    Texture2D* sample = SpriteLoader::GetSprite(NONE);
    size = {static_cast<float>(x), 0, static_cast<float>(sample->width), static_cast<float>(sample->height)};
}

void Stack::Draw() {
    DrawTexture(((last== nullptr)?*SpriteLoader::GetSprite(NONE):*SpriteLoader::GetSprite(last->GetCardId())), size.x,size.y,WHITE);
}

bool Stack::Drop(Card *card) {
    int cardId = card->GetCardId();
    if(last == nullptr){
        if((cardId & RANK_MASK) == ACE){
            last = card;
            return true;
        }else{
            return false;
        }
    }
    int lastId = last->GetCardId();

    if(((lastId & RANK_MASK) >> 2) - ((cardId & RANK_MASK) >> 2) == -1 && (lastId&COLOR_MASK) == (cardId&COLOR_MASK)){
        delete last;
        last = card;
        return true;
    }


    return false;
}

Rectangle Stack::GetSize() {
    return size;
}
