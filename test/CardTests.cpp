#pragma once
#include "gtest/gtest.h"
#include "CardDefinitions.h"

#include "Card.h"

TEST(CardTests, CorrectId){
    Card card(SIX|CLUB);

    ASSERT_EQ(card.GetCardId(), SIX|CLUB);
}

TEST(CardTests, CardIdLowerEdgeCase){
    Card card(ACE|SPADE);

    ASSERT_EQ(card.GetCardId(), ACE|SPADE);
}
TEST(CardTests, CardIdHigherEdgeCase){
    Card card(KING|DIAMOND);

    ASSERT_EQ(card.GetCardId(), KING|DIAMOND);
}
TEST(CardTests, InvalidCardId){
    Card card(2137);

    ASSERT_EQ(card.GetCardId(), NONE);
}
