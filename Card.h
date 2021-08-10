#pragma once
#include "raylib.h"
#include "State.h"
#include "Point.h"
#include "SpriteLoader.h"
#include "CardDefinitions.h"

class Card {
public:
    int cardId = NONE;
    bool IsVisible();
    void Update();
    void Draw();
    void Show();
    Card(int cardId);
    Card* nextInStack;
    Rectangle rect;
private:
    bool isVisible = false;
    Texture2D* sprite;

};
