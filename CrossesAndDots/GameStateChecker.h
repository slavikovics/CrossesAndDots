#pragma once
#include "ScenesBuilder.h"

class GameStateChecker
{
	public:

		GameStateChecker(int fieldDimension, GameField& gameField)
		{
			_fieldDimension = fieldDimension;
			_gameField = gameField;
		}

		string CheckVertical()
		{
			int countInRow;

			string winner;

			for (int i = 0; i < _fieldDimension; i++)
			{
				winner = StateNone;
				countInRow = 0;

				for (int j = 0; j < _fieldDimension; j++)
				{
					string currentField = _gameField.GetField2(i, j);
					if (j == 0) winner = currentField;
					if (winner == StateNone) countInRow = -1;
					if (winner != currentField) countInRow = -1;
					countInRow++;
				}

				if (countInRow == _fieldDimension) return winner;
			}

			return StateNone;
		}

		string CheckHorizontal()
		{
			int countInRow;

			string winner;

			for (int i = 0; i < _fieldDimension; i++)
			{
				winner = StateNone;
				countInRow = 0;

				for (int j = 0; j < _fieldDimension; j++)
				{
					string currentField = _gameField.GetField2(j, i);

					if (j == 0) winner = currentField;
					if (winner == StateNone) countInRow = -1;
					if (winner != currentField) countInRow = -1;
					countInRow++;
				}

				if (countInRow == _fieldDimension) return winner;
			}

			return StateNone;
		}
		
		string CheckD1()
		{
			string winner = StateNone;

			for (int i = 0; i < _fieldDimension; i++)
			{
				string currentField = _gameField.GetField2(i, i);
				if (i == 0) winner = currentField;
				if (currentField == StateNone) return StateNone;
				if (currentField != winner) return StateNone;
			}

			return winner;
		}

		string CheckD2()
		{

			string winner = StateNone;

			int x = 0;

			for (int i = _fieldDimension - 1; i >= 0; i--)
			{
				string currentField = _gameField.GetField2(x, i);
				if (x == 0) winner = currentField;
				if (currentField == StateNone) return StateNone;
				if (currentField != winner) return StateNone;
				x++;
			}

			return winner;
		}

		string CheckTie()
		{
			for (int i = 0; i < _fieldDimension; i++)
			{
				for (int j = 0; j < _fieldDimension; j++)
				{
					if (_gameField.GetField2(i, j) == StateNone) return StateNone;
				}
			}

			return StateTie;
		}

		string CheckGameState()
		{
			string s = _gameField.GetField2(0, 0);

			string state = CheckVertical();
			if (state != StateNone) return state;

			state = CheckHorizontal();
			if (state != StateNone) return state;

			state = CheckD1();
			if (state != StateNone) return state;

			state = CheckD2();
			if (state != StateNone) return state;

			state = CheckTie();
			if (state != StateNone) return state;

			return StateNone;
		}

	private:

		const string StateZero = "zero";
		const string StateCross = "cross";
		const string StateTie = "tie";
		const string StateNone = "none";

	   GameField _gameField;
	   int _fieldDimension;

};