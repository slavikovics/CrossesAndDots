#pragma once
#include "GameStates.h"

/// <summary>
/// Class for storing and getting the information about game field and it's elements.
/// </summary>
class GameField
{
	public:	

		/// <summary>
		/// Constructor for GameField, calls void SetFieldDimension(int d)
		/// </summary>
		/// <param name="dimension">: dimension of GameField</param>
		GameField(int dimension);

		/// <summary>
		/// Constructor for copied instances (for the field of GameStateChecker). Requires operator= call.
		/// </summary>
		GameField();
 
		/// <summary>
		/// Calls delete[] for int** fields field, skips deleting if destructor is called from an instance,
	    /// in which bool isACopy equals to true.
		/// </summary>
		~GameField();
		
		/// <summary>
		/// Overwrites int fieldDimension and int** fields with those properties of gameField
		/// </summary>
		/// <param name="gameField">GameField& gameField</param>
		/// <returns>GameField& gameField</returns>
		GameField& operator = (GameField& gameField);

		int& operator[](int index);
		
		/// <summary>
		/// Method for setting a zero in a GameField. Tries to set zero in the given position.
		/// </summary>
		/// <param name="y">: index of GameField element</param>
		/// <param name="x">: index of GameField element</param>
		/// <returns>Returns true if zero was successfully set, returns false if zero can't be set in the given position.</returns>
		bool SetZero(int y, int x);

		/// <summary>
		/// Method for setting a cross in a GameField. Tries to set cross in the given position.
		/// </summary>
		/// <param name="x">: index of GameField element</param>
		/// <param name="y">: index of GameField element</param>
		/// <returns>Returns true if cross was successfully set, returns false if cross can't be set in the given position.</returns>
		bool SetCross(int y, int x);

		/// <summary>
		/// </summary>
		/// <returns>int dimension</returns>
		int GetDimension();
		
		/// <summary>
		/// Returns GameState of GameField element
		/// </summary>
		/// <param name="x">row of the GameField (starts from 0)</param>
		/// <param name="y">column of the GameField (starts from 0)</param>
		/// <returns>string</returns>
		string GetField2(int x, int y);

		bool IsACopy();

	private:

		/// <summary>
		/// Stores the dimensions of GameField
		/// </summary>
		int fieldDimension;
		
		/// <summary>
		/// Is used to store GameStates of particular GameField elements in int values.
		/// 0: GameStates.StateNone
		/// 1: GameStates.StateCross
		/// 2: GameState.StateZero
		/// </summary>
		int** fields;
		
		/// <summary>
		/// Is used to differenciate instance of GameField, which was created in GameStateChecker 
		/// and outside of it to optimize destructor calls of GameField.
		/// </summary>
		bool isACopy;

		GameStates gameStates;
		
		/// <summary>
		/// Sets game field dimension. Initializes int** fields.
		/// If conditions are not passes the method sets a default dimension of 3.
		/// </summary>
		/// <param name="d">Acceptable dimensions values: value must be greater than 0 and value must be less or equal to 20. </param>
		void SetFieldDimension(int d);

		string GetField(int index);
};

