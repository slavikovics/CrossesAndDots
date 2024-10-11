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

	GameField gameFieldEmpty;
	EXPECT_EQ(gameFieldEmpty.GetDimension(), 0);
	EXPECT_EQ(gameFieldEmpty.IsACopy(), true);
}

TEST(GameFieldTest, GetField2Test)
{
	GameField gameField(5);
	EXPECT_EQ(gameField.GetField2(10, 10), (string)"wrong arguments");

	EXPECT_EQ(gameField.GetField2(-10, -10), (string)"wrong arguments");
}

TEST(GameFieldTest, OperatorTest)
{
	GameField gameField(5);
	gameField[5] = 1;
	EXPECT_EQ(gameField[5], 1);
	gameField[5] = 312;
	EXPECT_EQ(gameField[5], 312);
	gameField[5] = -12;
	EXPECT_EQ(gameField[5], -12);
	gameField[5] = 0;
	EXPECT_EQ(gameField[5], 0);
}

TEST(GameFieldTest, SetZeroTest)
{
	GameField gameField(3);
	GameStates gameStates;
	gameField.SetZero(0, 0);
	EXPECT_EQ(gameField.GetField2(0, 0), gameStates.StateZero);

	gameField.SetZero(1, 1);
	EXPECT_EQ(gameField.GetField2(1, 1), gameStates.StateZero);

	EXPECT_EQ(gameField.SetZero(-1, -1), false);

	EXPECT_EQ(gameField.SetZero(10, 10), false);
}

TEST(GameFieldTest, SetCrossTest)
{
	GameField gameField(3);
	GameStates gameStates;
	gameField.SetCross(0, 0);
	EXPECT_EQ(gameField.GetField2(0, 0), gameStates.StateCross);

	gameField.SetCross(1, 1);
	EXPECT_EQ(gameField.GetField2(1, 1), gameStates.StateCross);

	EXPECT_EQ(gameField.SetCross(-1, -1), false);

	EXPECT_EQ(gameField.SetCross(10, 10), false);
}
