#include "pch.h"
#include "CppUnitTest.h"
#include "../CrossesAndDots/Player.cpp"
#include "../CrossesAndDots/GameStateChecker.cpp"
#include "../CrossesAndDots/GameField.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MicrosoftUnitTests
{
	TEST_CLASS(GameFieldTests)
	{
	public:
		
		/// <summary>
		/// Testting constructor GameField(int dimension);
		/// </summary>
		TEST_METHOD(ConstructorTest)
		{
			GameField gameField(5);
			GameStates gameStates;
			Assert::AreEqual(5, gameField.GetDimension());
			for (int i = 0; i < gameField.GetDimension(); i++)
			{
				for (int j = 0; j < gameField.GetDimension(); j++)
				{
					Assert::AreEqual(gameField.GetField2(i, j), gameStates.StateNone);
				}
			}
		}

		/// <summary>
		/// Testing operator []
		/// </summary>
		TEST_METHOD(OperatorTest1)
		{
			GameField gameField(5);
			gameField[5] = 1;
			Assert::AreEqual(gameField[5], 1);
			gameField[5] = 312;
			Assert::AreEqual(gameField[5], 312);
			gameField[5] = -12;
			Assert::AreEqual(gameField[5], -12);
			gameField[5] = 0;
			Assert::AreEqual(gameField[5], 0);
		}

		/// <summary>
		/// Testing operator =
		/// </summary>
		TEST_METHOD(OperatorTest2)
		{

		}
	};
}
