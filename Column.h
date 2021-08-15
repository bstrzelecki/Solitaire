#pragma once

#include "classes.fwd"
#include <stack>
#include "raylib.h"

class Column {
public:
    Column(int x);
    bool IsHovering(int x, int y);
    bool IsPlaceableColor(int cardId) const;
    [[nodiscard]] Rectangle GetSize() const;
    void Draw() const;
    void Update();
    void AddCard(Card* card);
    void ShowFirstCard();
private:
    Rectangle size;
    Card* start = nullptr;
    Card* end = nullptr;
    static bool isDragging;
    Card* cards = nullptr;
};


#include "SpriteLoader.h"
#include "Card.h"
#include "State.h"
