#include <iostream>
#include "GameStateChecker.h"

using namespace std;

void NewGame()
{
	int dimension;
	int x;
	int y;
	string nowActions = "X";
	string gameState = "";

	cout << "Enter field dimensions" << endl;
	cin >> dimension;

	GameField gameField = GameField(dimension);
	GameStateChecker gameStateChecker = GameStateChecker(dimension, gameField);
	
	system("cls");

	while (true)
	{

		cout << ScenesBuilder::GameBuild(gameField);
		
		cout << " Now actions: " << nowActions << endl;
		gameState = gameStateChecker.CheckGameState();

		cout << " Winner: " << gameState << endl;
		

		if (gameState != "none")
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