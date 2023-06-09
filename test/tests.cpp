#include <сtest.h>

#include <include/board.h>
#include <include/swap.h>

#include <limits.h>


CTEST(SwapNumbers, positive_case) {
  /*
  Check swap functionality
  */
  int first = 0, second = 1;
  Swap(first, second);
  ASSERT_EQUAL(1, first);
  ASSERT_EQUAL(0, second);
}

CTEST(SwapNumbers, min_max_case) {
  /*
  Check swap functionality with limits
  */
  int first = INT_MAX, second = INT_MIN;
  Swap(first, second);
  ASSERT_EQUAL(INT_MIN, first);
  ASSERT_EQUAL(INT_MAX, second);
}

CTEST(BoardFunctionality, constructor) {
  /*
  Check if we can create board with negative size
  */
  try {
    Board board(-1);
  } catch (const char *message) {
    CTEST_LOG("%s", message);
  }
}

CTEST(BoardFunctionality, generation_board) {
  /*
  Check if we win on game start
  */
  Board board(5);
  board.GenerateBoard();
  ASSERT_FALSE(board.CheckWin());
}

CTEST(BoardFunctionality, try_move) {
  /*
  Check if invalid direction would work
  */
  Board board(5);
  board.GenerateBoard();

  try {
    board.TryMove((DIRECTION)10);
  } catch (const char *message) {
    CTEST_LOG("%s", message);
  }
}
