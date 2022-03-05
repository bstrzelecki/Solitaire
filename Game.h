#pragma once
#include "classes.fwd"
#include <random>
#include <array>
#include "Card.h"
#include "Deck.h"
#include "Column.h"
#include "Hand.h"
#include "Stack.h"
#include <algorithm>


class Game {
public:
    Game();
    void Start();
    ~Game();
    bool DropCard(Card *card);
    bool DropRange(Card* start, Card* end);
    Hand & GetHand();
private:
    Hand hand;
    Deck deck;
    std::array<Column, 7> columns;
    std::array<Stack, 4> stacks;
    const static int offset = 5;
};

