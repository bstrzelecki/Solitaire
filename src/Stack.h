#pragma once
#include "raylib.h"
#include "classes.fwd"

class Stack {
public:
    Stack(int x);
    void Draw();
    bool Drop(Card* card);

    Rectangle GetSize();

private:
    Rectangle size;
    Card* last = nullptr;
};

#include "Hand.h"
#include "CardDefinitions.h"
#include "SpriteLoader.h"

