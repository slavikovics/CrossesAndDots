#pragma once

#include "GameField.h"

class ScenesBuilder
{

  public:

	static string MenuBuild()
	{
		string output = "";
		output += "1 - Play\n";
		output += "2 - Exit\n";

		return output;
	}

	static string GameBuild(GameField & gameField)
	{
		int fieldDimension = gameField.GetDimension();

		string output = "";

		for (int i = 0; i < fieldDimension; i++)
		{
			for (int j = 0; j < fieldDimension; j++)
			{
				if (gameField.GetField2(i, j) == gameStates.StateNone)
				{
					output += " # ";
					continue;
				}

				if (gameField.GetField2(i, j) == gameStates.StateCross)
				{
					output += " X ";
					continue;
				}

				if (gameField.GetField2(i, j) == gameStates.StateZero)
				{
					output += " O ";
					continue;
				}
			}

			output += "\n";
		}

		return output;
	}
};