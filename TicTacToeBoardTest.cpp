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
TEST(TicTacToeBoardTest, placePiece_ValidLocationTest)
{
	//TicTacToeBoard ttt;
	ASSERT_TRUE(ttt.placePiece(0,0) == X);
	ASSERT_TRUE(ttt.placePiece(1,1) == O);
}

TEST(TicTacToeBoardTest, placePiece_invalidLocationTest)
{
	ASSERT_TRUE(ttt.placePiece(3,1) == Invalid);
	ASSERT_TRUE(ttt.placePiece(5, 1) == Invalid);
	ASSERT_TRUE(ttt.placePiece(1,3) == Invalid);
	ASSERT_TRUE(ttt.placePiece(1, 5) == Invalid);
	ASSERT_TRUE(ttt.placePiece(-1,1) == Invalid);
	ASSERT_TRUE(ttt.placePiece(1, -1) == Invalid);
}

TEST(TicTacToeBoardTest, placePiece_replaceTest)
{
	ASSERT_TRUE(ttt.placePiece(0,0) == X);
}

TEST(TicTacToeBoardTest, getPieceTest_ValidLocationTest)
{
	ASSERT_TRUE(ttt.getPiece(0,0) == X);
	ASSERT_TRUE(ttt.getPiece(1,1) == O);
	ASSERT_TRUE(ttt.getPiece(1,2) == Blank);
}

TEST(TicTacToeBoardTest, getPiece_InvalidLocationTest)
{
	ASSERT_TRUE(ttt.getPiece(3,3) == Invalid);
	ASSERT_TRUE(ttt.getPiece(-1,-3) == Invalid);

}
TEST(TicTacToeBoardTest, getWinnerTest) {
	ASSERT_TRUE(ttt.placePiece(1,0) == X);
	ASSERT_TRUE(ttt.placePiece(0,1) == X);
	ASSERT_TRUE(ttt.placePiece(2,0) == X);
	ASSERT_TRUE(ttt.getWinner() == X);
}
