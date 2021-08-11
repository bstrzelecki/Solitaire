#pragma once

#include <random>
#include <array>
#include "Card.h"
#include "Hand.h"
#include "Deck.h"
#include "Column.h"



class Game {
public:
    Game();
    void Start();
    ~Game();
private:
    Hand hand;
    Deck deck;
    std::array<Column, 7> columns;
    const static int offset = 5;
};