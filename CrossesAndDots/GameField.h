#pragma once
#include "GameStates.h"

class GameField
{

   // 0 - no element
   // 1 - cross
   // 2 - zero

  public:
	GameField(int dimension);
	GameField();
	~GameField();

	GameField& operator = (GameField& gameField)
	{
		fieldDimension = gameField.GetDimension();
		fields = gameField.fields;
		return *this;
	}

  private:
	int fieldDimension;
	int** fields;
	bool isACopy;
	GameStates gameStates;

	// Sets game field dimension. Acceptable d values: d >= 2 && d <= 20. Default: 3.

	void SetFieldDimension(int d)
	{
		if (d < 2 || d > 20) d = 3;

		fieldDimension = d;

		fields = new int*[fieldDimension];

		for (int i = 0; i < fieldDimension; i++)
		{
			fields[i] = new int[fieldDimension];
		}

		for (int i = 0; i < fieldDimension; i++)
		{
			for (int j = 0; j < fieldDimension; j++)
			{
				fields[i][j] = 0;
			}
		}
	}

	string GetField(int index)
	{
		unsigned x = index % fieldDimension;
		unsigned y = index / fieldDimension;
		return GetField2(x, y);
	}

	public:	

	int GetDimension()
	{
		return fieldDimension;	
	}

	string operator[](int x)
	{
		return gameStates.StateNone;
	}

	string GetField2(int x, int y)
	{
		if (x >= fieldDimension || y >= fieldDimension || x < 0 || y < 0) return "wrong arguments";
		if (fields[x][y] == 1) return gameStates.StateCross;
		if (fields[x][y] == 2) return gameStates.StateZero;
		else return gameStates.StateNone;
	}

	bool SetZero(int y, int x)
	{
		if (GetField2(x, y) == gameStates.StateNone)
		{
			fields[x][y] = 2;
			return true;
		}

		return false;
	}

	// Method for setting a cross in a GameField. Tries to set cross in the given position. 
	// Returns true if the cross was successfully set, 
	// returns false if cross can't be set in the given position
	bool SetCross(int y, int x)
	{
		if (GetField2(x, y) == gameStates.StateNone)
		{
			fields[x][y] = 1;
			return true;
		}

		return false;
	}
};

// Constructor for main instances
GameField::GameField(int dimension)
{
	isACopy = false;
	SetFieldDimension(dimension);
}

// Constructor for copied instances (for the field of GameStateChecker). Requires operator= call.
GameField::GameField()
{
	fieldDimension = 0;
	fields = NULL;
	isACopy = true;
}

// Destructor is only called in main instances
GameField::~GameField()
{
	if (isACopy) return;
	
	for (int i = 0; i < fieldDimension; i++)
	{
		delete[] fields[i];
	}
	
	delete[] fields;
}
