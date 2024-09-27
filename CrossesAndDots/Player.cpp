#include <iostream>
#include "GameStateChecker.h"

using namespace std;

GameStates gameStates;

void GameInformation(string nowActions, string gameState)
{
	cout << " Now actions: " << nowActions << endl;
	cout << " Winner: " << gameState << endl;
}

/// <summary>
/// Handles all game operations, checks and console updates
/// </summary>
/// <param name="nowActions">represents whose turn to make a move</param>
/// <param name="gameState">represents who is winning</param>
/// <param name="gameField">GameField& gameField</param>
/// <param name="gameStateChecker">GameStateChecker& gameStateChecker</param>
void GameCycle(string nowActions, string gameState, GameField& gameField, GameStateChecker& gameStateChecker)
{
	int x;
	int y;

	while (true)
	{
		cout << ScenesBuilder::GameBuild(gameField);
		gameState = gameStateChecker.CheckGameState();
		GameInformation(nowActions, gameState);

		if (gameState != gameStates.StateNone)
		{
			system("pause");
			return;
		}

		cin >> x >> y;
		system("cls");

		if (nowActions == gameStates.StateCross)
		{
			if (!gameField.SetCross(x - 1, y - 1)) continue;
			nowActions = gameStates.StateZero;
		}

		else if (nowActions == gameStates.StateZero)
		{
			if (!gameField.SetZero(x - 1, y - 1)) continue;
			nowActions = gameStates.StateCross;
		}
	}
}

/// <summary>
/// Launches new game
/// </summary>
void NewGame()
{
	int dimension;
	string nowActions = gameStates.StateCross;
	string gameState = gameStates.StateNone;

	cout << "Enter field dimensions" << endl;
	cin >> dimension;
	system("cls");

	GameField gameField(dimension);
	GameStateChecker gameStateChecker(dimension, gameField);

	GameCycle(nowActions, gameState, gameField, gameStateChecker);
	
	system("cls");
}

/// <summary>
/// Called at the start of the programm
/// </summary>
/// <returns>0 if ended successfully</returns>
int main()
{
	while (true)
	{
		string menu = ScenesBuilder::MenuBuild();
		int key;

		cout << menu;
		cin >> key;

		switch (key)
		{
			case 1:
				system("cls");
				NewGame();
				break;

			case 2:
				return 0;
		}
		system("cls");
	}

	return 0;
}