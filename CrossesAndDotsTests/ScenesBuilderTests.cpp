#include "pch.h"
#include "../CrossesAndDots/ScenesBuilder.h"

TEST(ScenesBuilderTest, GameBuildTest)
{
	GameField gameField(3);
	gameField.SetCross(0, 0);
	string resp = ScenesBuilder::GameBuild(gameField);
	EXPECT_EQ(resp, (string)" X  #  # \n #  #  # \n #  #  # \n");

	gameField.SetCross(0, 0);
	gameField.SetCross(1, 1);
	resp = ScenesBuilder::GameBuild(gameField);
	EXPECT_EQ(resp, (string)" X  #  # \n #  X  # \n #  #  # \n");
}