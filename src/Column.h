#pragma once

#include <stack>
#include "raylib.h"
#include "SpriteLoader.h"
#include "classes.fwd"


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
    static bool isDragging;
private:
    Rectangle size;
    Card* start = nullptr;
    Card* end = nullptr;
    Card* cards = nullptr;
};

#include "Card.h"

