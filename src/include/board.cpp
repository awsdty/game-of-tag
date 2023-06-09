#include <include/board.h>

Board::Board(int size) {
  if (size < 0) {
    throw "Размер не может быть отрицательным!";
  }
  this->size = size;
  board = new int *[size];
  for (int i = 0; i < size; i++) {
    board[i] = new int[size];
  }
}

Board::~Board() {
  for (int i = 0; i < size; i++) {
    delete[] board[i];
  }
  delete[] board;
}

bool Board::CheckWin() {

  for (int i = 0; i < size; i++) {

    for (int j = 0; j < size; j++) {

      if (board[i][j] != (1 + j + i * size)) {
        if ((i == size - 1) && (j == size - 1)) {
          return true;
        }
        return false;
      }
    }
  }
  return true;
}

void Board::TryMove(DIRECTION dir) {
  if (int(dir) < 0 || int(dir) > 3) {
    throw "Неправильное направление!";
  }
  switch (dir) {
  case UP:
    if (null_i != 0) {
      Swap(board[null_i][null_j], board[null_i - 1][null_j]);
      null_i -= 1;
    }
    break;
  case DOWN:
    if (null_i != size - 1) {
      Swap(board[null_i][null_j], board[null_i + 1][null_j]);
      null_i += 1;
    }
    break;
  case LEFT:
    if (null_j != 0) {
      Swap(board[null_i][null_j], board[null_i][null_j - 1]);
      null_j -= 1;
    }
    break;
  case RIGHT:
    if (null_j != size - 1) {
      Swap(board[null_i][null_j], board[null_i][null_j + 1]);
      null_j += 1;
    }
    break;

  default:
    break;
  }
}

void Board::ShowBoard() {

 
  for (int i = 0; i < size; i++) {
    std::cout << std::setw(size) ;
  }
  std::cout << '\n';

  for (int i = 0; i < size; i++) {
   
    for (int j = 0; j < size; j++) {
      std::cout << std::setw(size) <<  std::to_string(board[i][j]);
    }
    std::cout << '\n';


    for (int j = 0; j < size; j++) {
      std::cout << std::setw(size) ;
    }
    std::cout << '\n';
  }
}

void Board::GenerateBoard() {

  std::srand(time(0));

  for (int i = 0; i < size; i++) {

    for (int j = 0; j < size; j++) {

      if ((i != size - 1) || (j != size - 1)) {
        board[i][j] = 1 + j + i * size;
      } else {
        board[i][j] = 0;
        null_i = i;
        null_j = j;
      }
    }
  }

  for (int i = 0; i < 1500; i++) {
    TryMove(DIRECTION(std::rand() % 4));
  }
}