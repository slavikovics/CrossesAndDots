#pragma once
#include "GameStates.h"

class GameField
{
	public:	

		GameField(int dimension);

		GameField();

		~GameField();

		GameField& operator = (GameField& gameField);

		int& operator[](int index);

		bool SetZero(int y, int x);

		/// Method for setting a cross in a GameField. Tries to set cross in the given position. 
		/// Returns true if the cross was successfully set, 
		/// returns false if cross can't be set in the given position
		bool SetCross(int y, int x);

		int GetDimension();

		string GetField2(int x, int y);

	private:

		int fieldDimension;

		int** fields;

		bool isACopy;

		GameStates gameStates;

		// Sets game field dimension. Acceptable d values: d >= 2 && d <= 20. Default: 3.

		void SetFieldDimension(int d);

		string GetField(int index);
};

