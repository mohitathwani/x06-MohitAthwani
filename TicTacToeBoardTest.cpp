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
TEST(TicTacToeBoardTest, placePiece_Valid_Location_Test)
{
	//TicTacToeBoard ttt;
	ASSERT_TRUE(ttt.placePiece(0,0) == X);
	ASSERT_TRUE(ttt.placePiece(1,1) == O);
}

TEST(TicTacToeBoardTest, placePiece_Row_Equals_3_Col_Valid)
{
	ASSERT_TRUE(ttt.placePiece(3,1) == Invalid);
}

TEST(TicTacToeBoardTest, placePiece_Row_Greater_Than_3_Col_Valid)
{
	ASSERT_TRUE(ttt.placePiece(5, 1) == Invalid);
}

TEST(TicTacToeBoardTest, placePiece_Row_Less_Than_0_Col_Valid)
{
	ASSERT_TRUE(ttt.placePiece(-1,1) == Invalid);
}

TEST(TicTacToeBoardTest, placePiece_Row_Valid_Col_Equals_3)
{
	ASSERT_TRUE(ttt.placePiece(1,3) == Invalid);
}

TEST(TicTacToeBoardTest, placePiece_RowValidColGreaterThan3)
{
	ASSERT_TRUE(ttt.placePiece(1, 5) == Invalid);
}

TEST(TicTacToeBoardTest, placePiece_Row_Valid_Col_Less_Than_0)
{
	ASSERT_TRUE(ttt.placePiece(1, -1) == Invalid);
}

TEST(TicTacToeBoardTest, placePiece_Replace_Test)
{
	ASSERT_TRUE(ttt.placePiece(0,0) == X);
}

TEST(TicTacToeBoardTest, getPieceTest_Valid_Location_Test)
{
	ASSERT_TRUE(ttt.getPiece(0,0) == X);
	ASSERT_TRUE(ttt.getPiece(1,1) == O);
	ASSERT_TRUE(ttt.getPiece(1,2) == Blank);
}

TEST(TicTacToeBoardTest, getPiece_Row_Equals_3_Col_Valid)
{
	ASSERT_TRUE(ttt.getPiece(3,1) == Invalid);
}

TEST(TicTacToeBoardTest, getPiece_Row_Greater_Than_3_Col_Valid)
{
	ASSERT_TRUE(ttt.getPiece(4,1) == Invalid);
}

TEST(TicTacToeBoardTest, getPiece_Row_Valid_Col_Equals_3)
{
	ASSERT_TRUE(ttt.getPiece(1,3) == Invalid);
}

TEST(TicTacToeBoardTest, getPiece_Row_Valid_Col_Greater_Than_3)
{
	ASSERT_TRUE(ttt.getPiece(1,4) == Invalid);
}

TEST(TicTacToeBoardTest, getPiece_Row_Less_Than_0_Col_Valid)
{
	ASSERT_TRUE(ttt.getPiece(-1,1) == Invalid);
}

TEST(TicTacToeBoardTest, getPiece_Row_Valid_Col_Less_Than_0)
{
	ASSERT_TRUE(ttt.getPiece(1,-1) == Invalid);
}

TEST(TicTacToeBoardTest, getWinnerTest_Horizontal) {
	ttt.clearBoard();
	ASSERT_TRUE(ttt.placePiece(0,0) == X);
	ASSERT_TRUE(ttt.placePiece(1,0) == O);
	ASSERT_TRUE(ttt.placePiece(0,1) == X);
	ASSERT_TRUE(ttt.placePiece(1,1) == O);
	ASSERT_TRUE(ttt.placePiece(0,2) == X);
	ASSERT_TRUE(ttt.getWinner() == X);
}

TEST(TicTacToeBoardTest, getWinnerTest_Vertical)
{
	ttt.clearBoard();
	ASSERT_TRUE(ttt.placePiece(0,0) == X);
	ASSERT_TRUE(ttt.placePiece(0,1) == O);
	ASSERT_TRUE(ttt.placePiece(1,0) == X);
	ASSERT_TRUE(ttt.placePiece(0,2) == O);
	ASSERT_TRUE(ttt.placePiece(2,0) == X);
	ASSERT_TRUE(ttt.getWinner() == X);

}

TEST(TicTacToeBoardTest, getWinnertest_LeftDiagonal)
{
	ttt.clearBoard();
	ASSERT_TRUE(ttt.placePiece(0,0) == X);
	ASSERT_TRUE(ttt.placePiece(0,1) == O);
	ASSERT_TRUE(ttt.placePiece(1,1) == X);
	ASSERT_TRUE(ttt.placePiece(2,0) == O);
	ASSERT_TRUE(ttt.placePiece(2,2) == X);
	ASSERT_TRUE(ttt.getWinner() == X);

}

TEST(TicTacToeBoardTest, getWinnerTest_RightDiagonal)
{
	ttt.clearBoard();
	ASSERT_TRUE(ttt.placePiece(0,2) == X);
	ASSERT_TRUE(ttt.placePiece(0,1) == O);
	ASSERT_TRUE(ttt.placePiece(1,1) == X);
	ASSERT_TRUE(ttt.placePiece(2,1) == O);
	ASSERT_TRUE(ttt.placePiece(2,0) == X);
	ASSERT_TRUE(ttt.getWinner() == X);
}

TEST(TicTacToeBoardTest, getWinnerTest_Invalid)
{
	ttt.clearBoard();
	ASSERT_TRUE(ttt.placePiece(0,2) == X);
	ASSERT_TRUE(ttt.getWinner() == Invalid);
}

TEST(TicTacToeBoardTest, getWinnerTest_Blank)
{
	ttt.clearBoard();
	ASSERT_TRUE(ttt.placePiece(0,0) == X);
	ASSERT_TRUE(ttt.placePiece(1,1) == O);
	ASSERT_TRUE(ttt.placePiece(0,2) == X);
	ASSERT_TRUE(ttt.placePiece(0,1) == O);
	ASSERT_TRUE(ttt.placePiece(2,1) == X);
	ASSERT_TRUE(ttt.placePiece(1,0) == 0);
	ASSERT_TRUE(ttt.placePiece(1,2) == X);
	ASSERT_TRUE(ttt.placePiece(2,0) == O);
	ASSERT_TRUE(ttt.placePiece(2,2) == X);
	ASSERT_TRUE(ttt.getWinner() == Blank);
}
