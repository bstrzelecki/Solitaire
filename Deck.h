#pragma once


#include <raylib.h>
#include <stack>
#include <queue>
#include <list>
#include "Card.h"
#include "Hand.h"

class Deck {
public:
    void Update();
    Deck(Hand* hand, int x, int y);
    void Draw();
    void Add(Card* card);
private:
    void next();
    Hand* hand;
    Card* dragged = nullptr;
    Rectangle position;
    Texture2D* backSprite;
    std::stack<Card*> hidden;
    std::list<Card*> visible;
};