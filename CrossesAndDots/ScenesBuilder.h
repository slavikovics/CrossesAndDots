#pragma once
#include "GameField.h"

/// <summary>
/// Is used to generate Console output strings
/// </summary>
class ScenesBuilder
{

  public:

	/// <summary>
	/// Builds string representation of Menu
	/// </summary>
	/// <returns>: string representation of Menu</returns>
	static string MenuBuild()
	{
		string output = "";
		output += "1 - Play\n";
		output += "2 - Exit\n";

		return output;
	}

	/// <summary>
	/// Builds string representation of GameField intance
	/// </summary>
	/// <param name="gameField">: GameField instance</param>
	/// <returns>: string representation of GameField intance</returns>
	static string GameBuild(GameField & gameField)
	{
		GameStates gameStates;
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