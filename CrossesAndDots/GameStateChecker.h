#pragma once
#include "ScenesBuilder.h"

/// <summary>
/// Is used to check game state
/// </summary>
class GameStateChecker
{
	public:

		/// <summary>
		/// Constructor of GameStateChecker, which checks game state of GameField& gameField
		/// </summary>
		/// <param name="fieldDimension"></param>
		/// <param name="gameField"></param>
		GameStateChecker(int fieldDimension, GameField& gameField);

		/// <summary>
		/// Returns game state
		/// </summary>
		/// <returns>string</returns>
		string CheckGameState();

	private:

		GameStates gameStates;

	    GameField _gameField;

	    int _fieldDimension;

		/// <summary>
		/// Checks game state in columns
		/// </summary>
		/// <returns>Returns game state</returns>
		string CheckVertical();

		/// <summary>
		/// Checks game state in rows
		/// </summary>
		/// <returns>Returns game state</returns>
		string CheckHorizontal();

		/// <summary>
		/// Checks game state in diagonal from top left corner to right bottom.
		/// </summary>
		/// <returns>Returns game state</returns>
		string CheckD1();

		/// <summary>
		/// Checks game state in diagonal from bottom left corner to right top.
		/// </summary>
		/// <returns>Returns game state</returns>
		string CheckD2();

		/// <summary>
		/// Checks tie
		/// </summary>
		/// <returns>Returns game state</returns>
		string CheckTie();
};