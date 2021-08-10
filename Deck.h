#pragma once


#include <raylib.h>
#include <stack>
#include <queue>
#include "Card.h"

class Deck {
public:
    void Update();
    Deck(int x, int y);
    void Draw();
    void Add(Card* card);

private:
    void next();
    Rectangle position;
    Texture2D* backSprite;
    std::stack<Card*> hidden;
    std::queue<Card*> visible;
};