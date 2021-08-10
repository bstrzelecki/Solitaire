#pragma once

#include <stack>
#include "SpriteLoader.h"
#include "Card.h"
#include "raylib.h"

class Column {
public:
    Column(int x);
    bool IsHovering(int x, int y);
    bool IsPlaceableColor(int cardId);
    void Draw();
    void AddCard(Card* card);
    void ShowFirstCard();
private:
    Rectangle size;
    Card* cards = nullptr;
};

