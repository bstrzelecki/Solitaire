#pragma once

#include <raylib.h>
#include "Card.h"

class Hand {
public:
    void Draw();
    void PickCard(Card* card, Vector2 offset);
private:
    Vector2 dragOffset;
    Card* card = nullptr;
};

