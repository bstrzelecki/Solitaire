#pragma once
#include "classes.fwd"
#include <raylib.h>

class Hand {
public:
    explicit Hand(Game* game);
    void Draw();
    void Update();
    bool HasDropped();
    void PickCard(Card* card, Vector2 offset);
    void PickCard(Card* start, Card* end, Vector2 offset);
private:
    Game* game;
    bool hasDropped = false;
    Vector2 dragOffset {0,0};
    Card* card = nullptr;
    Card* first = nullptr;

};
#include "Card.h"
#include "Game.h"