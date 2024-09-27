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
		/// Testting constructor GameField(int dimension), GetDimension(), GetField(i, j)
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
		/// Testing GetField2()
		/// </summary>
		TEST_METHOD(GetField2Test)
		{
			GameField gameField(5);
			Assert::AreEqual(gameField.GetField2(10, 10), (string)"wrong arguments");

			Assert::AreEqual(gameField.GetField2(-10, -10), (string)"wrong arguments");
		}

		/// <summary>
		/// Testing operator []
		/// </summary>
		TEST_METHOD(OperatorTest)
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
		/// Testing SetZero()
		/// </summary>
		TEST_METHOD(SetZeroTest)
		{
			GameField gameField(3);
			gameField.SetZero(0, 0);
			Assert::AreEqual(gameField.GetField2(0, 0), gameStates.StateZero);

			gameField.SetZero(1, 1);
			Assert::AreEqual(gameField.GetField2(1, 1), gameStates.StateZero);

			Assert::AreEqual(gameField.SetZero(-1, -1), false);

			Assert::AreEqual(gameField.SetZero(10, 10), false);
		}

		/// <summary>
		/// Testing SetCross()
		/// </summary>
		TEST_METHOD(SetCrossTest)
		{
			GameField gameField(3);
			gameField.SetCross(0, 0);
			Assert::AreEqual(gameField.GetField2(0, 0), gameStates.StateCross);

			gameField.SetCross(1, 1);
			Assert::AreEqual(gameField.GetField2(1, 1), gameStates.StateCross);

			Assert::AreEqual(gameField.SetCross(-1, -1), false);

			Assert::AreEqual(gameField.SetCross(10, 10), false);
		}

	};

	TEST_CLASS(ScenesBuilderTests)
	{
		TEST_METHOD(GameBuildTest)
		{
			GameField gameField(3);
			gameField.SetCross(0, 0);
			string resp = ScenesBuilder::GameBuild(gameField);
			Assert::AreEqual(resp, (string)" X  #  # \n #  #  # \n #  #  # \n");

			gameField.SetCross(0, 0);
			gameField.SetCross(1, 1);
			resp = ScenesBuilder::GameBuild(gameField);
			Assert::AreEqual(resp, (string)" X  #  # \n #  X  # \n #  #  # \n");
		}
	};


}
