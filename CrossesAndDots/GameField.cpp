#include "GameField.h"

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

GameField& GameField::operator= (GameField& gameField)
{
	fieldDimension = gameField.GetDimension();
	fields = gameField.fields;
	return *this;	
}

int& GameField::operator[](int index)
{
	unsigned x = index % fieldDimension;
	unsigned y = index / fieldDimension;
	return fields[x][y];
}

void GameField::SetFieldDimension(int d)
{
	if (d < 2 || d > 20) d = 3;

	fieldDimension = d;

	fields = new int* [fieldDimension];

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

bool GameField::SetZero(int y, int x)
{
	if (GetField2(x, y) == gameStates.StateNone)
	{
		fields[x][y] = 2;
		return true;
	}

	return false;
}

bool GameField::SetCross(int y, int x)
{
	if (GetField2(x, y) == gameStates.StateNone)
	{
		fields[x][y] = 1;
		return true;
	}

	return false;
}

string GameField::GetField(int index)
{
	unsigned x = index % fieldDimension;
	unsigned y = index / fieldDimension;
	return GetField2(x, y);
}

int GameField::GetDimension()
{
	return fieldDimension;
}

string GameField::GetField2(int x, int y)
{
	if (x >= fieldDimension || y >= fieldDimension || x < 0 || y < 0) return "wrong arguments";
	if (fields[x][y] == 1) return gameStates.StateCross;
	if (fields[x][y] == 2) return gameStates.StateZero;
	else return gameStates.StateNone;
}
