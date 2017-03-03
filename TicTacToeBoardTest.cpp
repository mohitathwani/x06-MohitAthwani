/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TicTacToeBoard ttt;
TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);

}
TEST(TicTacToeBoardTest, placePieceTest)
{
	//TicTacToeBoard ttt;
	ASSERT_TRUE(ttt.placePiece(0,0) == X);
	ASSERT_TRUE(ttt.placePiece(1,1) == O);
	ASSERT_TRUE(ttt.placePiece(3,3) == Invalid);
	ASSERT_TRUE(ttt.placePiece(0,0) == X);
}

TEST(TicTacToeBoardTest, getPieceTest) {
	ASSERT_TRUE(ttt.getPiece(0,0) == X);
	ASSERT_TRUE(ttt.getPiece(1,1) == O);
	ASSERT_TRUE(ttt.getPiece(3,3) == Invalid);
	ASSERT_TRUE(ttt.getPiece(1,2) == Blank);
}

TEST(TicTacToeBoardTest, getWinnerTest) {
	ASSERT_TRUE(ttt.placePiece(1,0) == X);
	ASSERT_TRUE(ttt.placePiece(0,1) == X);
	ASSERT_TRUE(ttt.placePiece(2,0) == X);
	ASSERT_TRUE(ttt.getWinner() == X);
}
