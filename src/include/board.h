#pragma once

#include <include/swap.h>
#include <ctime>

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

enum DIRECTION { UP, DOWN, LEFT, RIGHT };

class Board {
public:
  Board(int size);
  ~Board();
  bool CheckWin();
  void TryMove(DIRECTION dir);
  void GenerateBoard();
  void ShowBoard();

private:
  int size;
  int **board;
  int null_i;
  int null_j;
};