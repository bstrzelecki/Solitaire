#include "Stack.h"

Stack::Stack(int x) {
    Texture2D* sample = SpriteLoader::GetSprite(NONE);
    size = {static_cast<float>(x), 0, static_cast<float>(sample->width), static_cast<float>(sample->height)};
}

void Stack::Draw() {
    DrawTexture(((last== nullptr)?*SpriteLoader::GetSprite(NONE):*SpriteLoader::GetSprite(last->GetCardId())), size.x,size.y,WHITE);
}

bool Stack::Drop(Card *card) {
    if(last == nullptr){
        if((card->GetCardId() & RANK_MASK) == ACE){
            delete last;
            last = card;
            return true;
        }else{
            return false;
        }
    }

    if(((last->GetCardId() & RANK_MASK) >> 2) - ((card->GetCardId() & RANK_MASK) >> 2) == -1 && (last->GetCardId()&COLOR_MASK) == (card->GetCardId()&COLOR_MASK)){
        delete last;
        last = card;
        return true;
    }


    return false;
}

Rectangle Stack::GetSize() {
    return size;
}
