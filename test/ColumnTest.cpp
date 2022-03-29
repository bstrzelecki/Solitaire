#include "gtest/gtest.h"

#include "CardDefinitions.h"

#include "Card.h"

#include "Column.h"

TEST(ColumnTests, PlaceableColorTest){
    Card cardA(TWO|SPADE);
    Card cardB(ACE|DIAMOND);
    Column column(0);
    
    column.AddCard(&cardA);

    ASSERT_TRUE(column.IsPlaceableColor(cardB.GetCardId()));
}
TEST(ColumnTests, InPlaceableColorTest){
    Card cardA(TWO|SPADE);
    Card cardB(ACE|CLUB);
    Column column(0);
    
    column.AddCard(&cardA);

    ASSERT_FALSE(column.IsPlaceableColor(cardB.GetCardId()));
}
