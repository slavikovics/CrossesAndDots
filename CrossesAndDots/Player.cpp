#include <iostream>
#include "GameStateChecker.h"

using namespace std;

GameStates gameStates;

void NewGame()
{
	int dimension;
	int x;
	int y;
	string nowActions = "X";
	string gameState = "";

	cout << "Enter field dimensions" << endl;
	cin >> dimension;

	GameField gameField(dimension);
	GameStateChecker gameStateChecker(dimension, gameField);
	
	system("cls");

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

		if (nowActions == "X")
		{
			if(!gameField.SetCross(x - 1, y - 1)) continue;
			nowActions = "0";
		}

		else if (nowActions == "0")
		{
			if(!gameField.SetZero(x - 1, y - 1)) continue;
			nowActions = "X";
		}
	}
}

void GameInformation(string nowActions, string gameState)
{
	cout << " Now actions: " << nowActions << endl;
	cout << " Winner: " << gameState << endl;
}


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