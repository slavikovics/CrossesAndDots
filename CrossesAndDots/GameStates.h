#pragma once
#include <string>

using namespace std;

/// <summary>
/// Class for storing constants of game states.
/// Constatnts are used for both GameField elements and for GameStateChecker results.
/// </summary>
class GameStates
{
  public:

	const string StateZero = "zero";

	const string StateCross = "cross";

	const string StateTie = "tie";

	const string StateNone = "none";
};