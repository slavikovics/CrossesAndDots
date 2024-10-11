#include "pch.h"
#include "../CrossesAndDots/GameField.h"

TEST(GameFieldTest, ConstructorTest) {
	GameField gameField(5);
	GameStates gameStates;
	EXPECT_EQ(5, gameField.GetDimension());
	for (int i = 0; i < gameField.GetDimension(); i++)
	{
		for (int j = 0; j < gameField.GetDimension(); j++)
		{
			EXPECT_EQ(gameField.GetField2(i, j), gameStates.StateNone);
		}
	}
}