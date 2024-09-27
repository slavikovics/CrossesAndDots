#pragma once
#include "ScenesBuilder.h"

class GameStateChecker
{
	public:

		GameStateChecker(int fieldDimension, GameField& gameField);

		string CheckGameState();

	private:

		GameStates gameStates;

	    GameField _gameField;

	    int _fieldDimension;

		string CheckVertical();

		string CheckHorizontal();

		string CheckD1();

		string CheckD2();

		string CheckTie();
};