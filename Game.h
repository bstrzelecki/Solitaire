#pragma once
#include "classes.fwd"
#include <random>
#include <array>
#include "Card.h"
#include "Deck.h"
#include "Column.h"
#include "Hand.h"


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
    const static int offset = 5;
};

