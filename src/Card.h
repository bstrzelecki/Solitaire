#pragma once
#include "raylib.h"
#include "classes.fwd"
#include "State.h"
#include "SpriteLoader.h"
#include "CardDefinitions.h"

class Card {
public:
    bool IsVisible();
    void Draw();
    int GetCardId() const;
    void Show();
    Card(int cardId);
    Card* nextInStack;
    Rectangle rect;
private:
    int cardId = NONE;
    bool isVisible = false;
    Texture2D* sprite;

};
