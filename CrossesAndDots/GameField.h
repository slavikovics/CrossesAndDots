#pragma once
#include "GameStates.h"

/// Class for stroing and getting the information about game field and it's elements.
///  
class GameField
{
	public:	

		/// Constructor for GameField, calls void SetFieldDimension(int d)
		///
		GameField(int dimension);

		/// Constructor for copied instances (for the field of GameStateChecker). Requires operator= call.
		///
		GameField();

		/// Calls delete[] for int** fields field,
		/// skips deleting if destructor is called from an instance,
		/// in which bool isACopy equals to true. 
		~GameField();

		/// Overwrites int fieldDimension and int** fields
		/// fields with those properties of gameField 
		GameField& operator = (GameField& gameField);

		int& operator[](int index);

		/// Method for setting a zero in a GameField. Tries to set zero in the given position. 
		/// Returns true if the zero was successfully set, 
		/// returns false if zero can't be set in the given position.
		bool SetZero(int y, int x);

		/// Method for setting a cross in a GameField. Tries to set cross in the given position. 
		/// Returns true if the cross was successfully set, 
		/// returns false if cross can't be set in the given position.
		bool SetCross(int y, int x);

		int GetDimension();

		/// Returns GameState of GameField element 
		/// x: row of the GameField (starts from 0)
		/// y: column of the GameField (starts from 0)
		string GetField2(int x, int y);

	private:

		/// Stores the dimensions of GameField
		/// 
		int fieldDimension;

		// Is used to store GameStates of particular GameField elements in int values.
		// 0: GameStates.StateNone
		// 1: GameStates.StateCross
		// 2: GameState.StateZero
		int** fields;

		// Is used to differenciate instance of GameField, which was created in GameStateChecker 
		// and outside of it to optimize destructor calls of GameField.
		bool isACopy;

		GameStates gameStates;

		// Sets game field dimension. Initializes int** fields.
		// Acceptable dimensions values: value must be greater than 0 and value must be less or equal to 20. 
		// If conditions are not passes the method sets a default dimension of 3.
		void SetFieldDimension(int d);

		string GetField(int index);
};

