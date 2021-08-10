#pragma once

#include <raylib.h>
#include "Card.h"

class Hand {
public:
    void Draw();
private:
    Vector2 dragOffset;
    Card* card;
};

