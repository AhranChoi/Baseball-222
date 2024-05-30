#include "pch.h"
#include "../Tdd_BaseballKATA/Baseball.cpp"

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmatched) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}
