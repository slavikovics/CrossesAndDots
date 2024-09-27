#include "GameStateChecker.h"

GameStateChecker::GameStateChecker(int fieldDimension, GameField& gameField)
{
	_fieldDimension = fieldDimension;
	_gameField = gameField;
}

string GameStateChecker::CheckVertical()
{
	int countInRow;

	string winner;

	for (int i = 0; i < _fieldDimension; i++)
	{
		winner = gameStates.StateNone;
		countInRow = 0;

		for (int j = 0; j < _fieldDimension; j++)
		{
			string currentField = _gameField.GetField2(i, j);
			if (j == 0) winner = currentField;
			if (winner == gameStates.StateNone) countInRow = -1;
			if (winner != currentField) countInRow = -1;
			countInRow++;
		}

		if (countInRow == _fieldDimension) return winner;
	}

	return gameStates.StateNone;
}

string GameStateChecker::CheckHorizontal()
{
	int countInRow;

	string winner;

	for (int i = 0; i < _fieldDimension; i++)
	{
		winner = gameStates.StateNone;
		countInRow = 0;

		for (int j = 0; j < _fieldDimension; j++)
		{
			string currentField = _gameField.GetField2(j, i);

			if (j == 0) winner = currentField;
			if (winner == gameStates.StateNone) countInRow = -1;
			if (winner != currentField) countInRow = -1;
			countInRow++;
		}

		if (countInRow == _fieldDimension) return winner;
	}

	return gameStates.StateNone;
}

string GameStateChecker::CheckD1()
{
	string winner = gameStates.StateNone;

	for (int i = 0; i < _fieldDimension; i++)
	{
		string currentField = _gameField.GetField2(i, i);
		if (i == 0) winner = currentField;
		if (currentField == gameStates.StateNone) return gameStates.StateNone;
		if (currentField != winner) return gameStates.StateNone;
	}

	return winner;
}

string GameStateChecker::CheckD2()
{
	string winner = gameStates.StateNone;

	int x = 0;

	for (int i = _fieldDimension - 1; i >= 0; i--)
	{
		string currentField = _gameField.GetField2(x, i);
		if (x == 0) winner = currentField;
		if (currentField == gameStates.StateNone) return gameStates.StateNone;
		if (currentField != winner) return gameStates.StateNone;
		x++;
	}

	return winner;
}

string GameStateChecker::CheckTie()
{
	for (int i = 0; i < _fieldDimension; i++)
	{
		for (int j = 0; j < _fieldDimension; j++)
		{
			if (_gameField.GetField2(i, j) == gameStates.StateNone) return gameStates.StateNone;
		}
	}

	return gameStates.StateTie;
}

string GameStateChecker::CheckGameState()
{
	string state = CheckVertical();
	if (state != gameStates.StateNone) return state;

	state = CheckHorizontal();
	if (state != gameStates.StateNone) return state;

	state = CheckD1();
	if (state != gameStates.StateNone) return state;

	state = CheckD2();
	if (state != gameStates.StateNone) return state;

	state = CheckTie();
	if (state != gameStates.StateNone) return state;

	return gameStates.StateNone;
}