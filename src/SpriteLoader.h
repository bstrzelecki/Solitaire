#pragma once

#include "raylib.h"
#include "CardDefinitions.h"

namespace SpriteLoader{
    Texture2D* GetSprite(int cardId);
    void LoadSprites();

}