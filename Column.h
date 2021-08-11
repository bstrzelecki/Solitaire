#pragma once

#include <stack>
#include "SpriteLoader.h"
#include "Card.h"
#include "raylib.h"

class Column {
public:
    Column(int x);
    bool IsHovering(int x, int y);
    bool IsPlaceableColor(int cardId) const;
    Rectangle GetSize() const;
    void Draw() const;
    void Update();
    void AddCard(Card* card);
    void ShowFirstCard();
private:
    Rectangle size;
    Card* cards = nullptr;
};

