#include "SpriteLoader.h"

namespace SpriteLoader{
    Texture2D* sprites;
}


Texture2D* SpriteLoader::GetSprite(int cardId){
    return &sprites[cardId];
}

void SpriteLoader::LoadSprites(){

    sprites = new Texture2D[1 << 6];

    sprites[ACE|SPADE]   = LoadTexture("Sprites/ace_spades_white.png");
    sprites[ACE|HEART]   = LoadTexture("Sprites/ace_hearts_white.png");
    sprites[ACE|CLUB]    = LoadTexture("Sprites/ace_clubs_white.png");
    sprites[ACE|DIAMOND] = LoadTexture("Sprites/ace_diamonds_white.png");

    sprites[TWO|SPADE]   = LoadTexture("Sprites/2_spades_white.png");
    sprites[TWO|HEART]   = LoadTexture("Sprites/2_hearts_white.png");
    sprites[TWO|CLUB]    = LoadTexture("Sprites/2_clubs_white.png");
    sprites[TWO|DIAMOND] = LoadTexture("Sprites/2_diamonds_white.png");


    sprites[THREE|SPADE]   = LoadTexture("Sprites/3_spades_white.png");
    sprites[THREE|HEART]   = LoadTexture("Sprites/3_hearts_white.png");
    sprites[THREE|CLUB]    = LoadTexture("Sprites/3_clubs_white.png");
    sprites[THREE|DIAMOND] = LoadTexture("Sprites/3_diamonds_white.png");


    sprites[FOUR|SPADE]   = LoadTexture("Sprites/4_spades_white.png");
    sprites[FOUR|HEART]   = LoadTexture("Sprites/4_hearts_white.png");
    sprites[FOUR|CLUB]    = LoadTexture("Sprites/4_clubs_white.png");
    sprites[FOUR|DIAMOND] = LoadTexture("Sprites/4_diamonds_white.png");


    sprites[FIVE|SPADE]   = LoadTexture("Sprites/5_spades_white.png");
    sprites[FIVE|HEART]   = LoadTexture("Sprites/5_hearts_white.png");
    sprites[FIVE|CLUB]    = LoadTexture("Sprites/5_clubs_white.png");
    sprites[FIVE|DIAMOND] = LoadTexture("Sprites/5_diamonds_white.png");


    sprites[SIX|SPADE]   = LoadTexture("Sprites/6_spades_white.png");
    sprites[SIX|HEART]   = LoadTexture("Sprites/6_hearts_white.png");
    sprites[SIX|CLUB]    = LoadTexture("Sprites/6_clubs_white.png");
    sprites[SIX|DIAMOND] = LoadTexture("Sprites/6_diamonds_white.png");


    sprites[SEVEN|SPADE]   = LoadTexture("Sprites/7_spades_white.png");
    sprites[SEVEN|HEART]   = LoadTexture("Sprites/7_hearts_white.png");
    sprites[SEVEN|CLUB]    = LoadTexture("Sprites/7_clubs_white.png");
    sprites[SEVEN|DIAMOND] = LoadTexture("Sprites/7_diamonds_white.png");


    sprites[EIGHT|SPADE]   = LoadTexture("Sprites/8_spades_white.png");
    sprites[EIGHT|HEART]   = LoadTexture("Sprites/8_hearts_white.png");
    sprites[EIGHT|CLUB]    = LoadTexture("Sprites/8_clubs_white.png");
    sprites[EIGHT|DIAMOND] = LoadTexture("Sprites/8_diamonds_white.png");


    sprites[NINE|SPADE]   = LoadTexture("Sprites/9_spades_white.png");
    sprites[NINE|HEART]   = LoadTexture("Sprites/9_hearts_white.png");
    sprites[NINE|CLUB]    = LoadTexture("Sprites/9_clubs_white.png");
    sprites[NINE|DIAMOND] = LoadTexture("Sprites/9_diamonds_white.png");


    sprites[TEN|SPADE]   = LoadTexture("Sprites/10_spades_white.png");
    sprites[TEN|HEART]   = LoadTexture("Sprites/10_hearts_white.png");
    sprites[TEN|CLUB]    = LoadTexture("Sprites/10_clubs_white.png");
    sprites[TEN|DIAMOND] = LoadTexture("Sprites/10_diamonds_white.png");

    sprites[JACK|SPADE]   = LoadTexture("Sprites/jack_spades_white.png");
    sprites[JACK|HEART]   = LoadTexture("Sprites/jack_hearts_white.png");
    sprites[JACK|CLUB]    = LoadTexture("Sprites/jack_clubs_white.png");
    sprites[JACK|DIAMOND] = LoadTexture("Sprites/jack_diamonds_white.png");


    sprites[QUEEN|SPADE]   = LoadTexture("Sprites/queen_spades_white.png");
    sprites[QUEEN|HEART]   = LoadTexture("Sprites/queen_hearts_white.png");
    sprites[QUEEN|CLUB]    = LoadTexture("Sprites/queen_clubs_white.png");
    sprites[QUEEN|DIAMOND] = LoadTexture("Sprites/queen_diamonds_white.png");


    sprites[KING|SPADE]   = LoadTexture("Sprites/king_spades_white.png");
    sprites[KING|HEART]   = LoadTexture("Sprites/king_hearts_white.png");
    sprites[KING|CLUB]    = LoadTexture("Sprites/king_clubs_white.png");
    sprites[KING|DIAMOND] = LoadTexture("Sprites/king_diamonds_white.png");


    sprites[BACK]    = LoadTexture("Sprites/back_black_basic_white.png");
    sprites[NONE] = LoadTexture("Sprites/total_blank_front_white.png");
}