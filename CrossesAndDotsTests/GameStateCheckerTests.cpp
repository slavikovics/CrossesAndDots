#include "pch.h"
#include "../CrossesAndDots/GameStateChecker.h"

TEST(GameStateCheckerTests, CheckStateTestCross1)
{
	GameField gameField(3);
	GameStates gameStates;
	gameField.SetCross(0, 0);
	GameStateChecker gameStateChecker(3, gameField);
	EXPECT_EQ(gameStateChecker.CheckGameState(), gameStates.StateNone);

	gameField.SetCross(0, 1);
	gameField.SetCross(0, 2);
	EXPECT_EQ(gameStateChecker.CheckGameState(), gameStates.StateCross);
}

TEST(GameStateCheckerTests, CheckStateTestZero1)
{
	GameField gameField(3);
	GameStates gameStates;
	gameField.SetZero(0, 0);
	GameStateChecker gameStateChecker(3, gameField);
	EXPECT_EQ(gameStateChecker.CheckGameState(), gameStates.StateNone);

	gameField.SetZero(0, 1);
	gameField.SetZero(0, 2);
	EXPECT_EQ(gameStateChecker.CheckGameState(), gameStates.StateZero);
}

TEST(GameStateCheckerTests, CheckStateTestCross2)
{
	GameField gameField(3);
	GameStates gameStates;
	gameField.SetCross(0, 0);
	GameStateChecker gameStateChecker(3, gameField);
	EXPECT_EQ(gameStateChecker.CheckGameState(), gameStates.StateNone);

	gameField.SetCross(1, 0);
	gameField.SetCross(2, 0);
	EXPECT_EQ(gameStateChecker.CheckGameState(), gameStates.StateCross);
}

TEST(GameStateCheckerTests, CheckStateTestZero2)
{
	GameField gameField(3);
	GameStates gameStates;
	gameField.SetZero(0, 0);
	GameStateChecker gameStateChecker(3, gameField);
	EXPECT_EQ(gameStateChecker.CheckGameState(), gameStates.StateNone);

	gameField.SetZero(1, 0);
	gameField.SetZero(2, 0);
	EXPECT_EQ(gameStateChecker.CheckGameState(), gameStates.StateZero);
}

TEST(GameStateCheckerTests, CheckStateTestCross3)
{
	GameField gameField(3);
	GameStates gameStates;
	gameField.SetCross(0, 0);
	GameStateChecker gameStateChecker(3, gameField);
	EXPECT_EQ(gameStateChecker.CheckGameState(), gameStates.StateNone);

	gameField.SetCross(1, 1);
	gameField.SetCross(2, 2);
	EXPECT_EQ(gameStateChecker.CheckGameState(), gameStates.StateCross);
}

TEST(GameStateCheckerTests, CheckStateTestZero3)
{
	GameStates gameStates;
	GameField gameField(3);
	gameField.SetZero(0, 0);
	GameStateChecker gameStateChecker(3, gameField);
	EXPECT_EQ(gameStateChecker.CheckGameState(), gameStates.StateNone);

	gameField.SetZero(1, 1);
	gameField.SetZero(2, 2);
	EXPECT_EQ(gameStateChecker.CheckGameState(), gameStates.StateZero);
}

TEST(GameStateCheckerTests, CheckStateTestCross4)
{
	GameField gameField(3);
	GameStates gameStates;
	gameField.SetCross(0, 2);
	GameStateChecker gameStateChecker(3, gameField);
	EXPECT_EQ(gameStateChecker.CheckGameState(), gameStates.StateNone);

	gameField.SetCross(1, 1);
	gameField.SetCross(2, 0);
	EXPECT_EQ(gameStateChecker.CheckGameState(), gameStates.StateCross);
}

TEST(GameStateCheckerTests, CheckStateTestZero4)
{
	GameStates gameStates;
	GameField gameField(3);
	gameField.SetZero(0, 2);
	GameStateChecker gameStateChecker(3, gameField);
	EXPECT_EQ(gameStateChecker.CheckGameState(), gameStates.StateNone);

	gameField.SetZero(1, 1);
	gameField.SetZero(2, 0);
	EXPECT_EQ(gameStateChecker.CheckGameState(), gameStates.StateZero);
}