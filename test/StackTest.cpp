#include "gtest/gtest.h"
#include "Stack.h"
#include "CardMock.h"
#include "CardDefinitions.h"

using ::testing::Return;

TEST(StackTest, CorrectDropTest){
		Stack stack(0);
		CardMock* cardA = new CardMock;
		CardMock* cardB = new CardMock;

		EXPECT_CALL(*cardA, GetCardId).Times(2).WillRepeatedly(Return(ACE|HEART));
		EXPECT_CALL(*cardB, GetCardId).Times(1).WillRepeatedly(Return(TWO|HEART));

		ASSERT_TRUE(stack.Drop(cardA));
		ASSERT_TRUE(stack.Drop(cardB));
		testing::Mock::AllowLeak(cardA);
		delete cardB;

}
