#include <include/game_window.h>

void play() {

  std::string startMessage ="\033[1;35mПривет! Добро пожаловать в игру в пятнашки!\nВ этой игре ваша задача переместить все пятнашки на игровом поле,\nчтобы они оказались в правильном порядке от меньшей к большей\nP.S. 0 -не пятнашка и должен стоять в самом конце\033[0m\n\n";
  int move_counter=0;
  int size;

  do {
    system("clear");
    std::cout<<startMessage;
    std::cout << "Выберите размер поля(от 3x3 до 5х5): ";
    std::cin >> size;
  } while (size < 3 || size > 5);

  Board board(size);
  board.GenerateBoard();
  board.ShowBoard();
  
  while (true) {
    char input;
    input = std::getchar();
    //input=getch()
    switch (input) {
    case 'w':
      board.TryMove(UP);
      move_counter++;
      break;
    case 'a':
      board.TryMove(LEFT);
      move_counter++;
      break;
    case 's':
      board.TryMove(DOWN);
      move_counter++;
      break;
    case 'd':
      board.TryMove(RIGHT);
      move_counter++;
      break;

    default:
      break;
    }
    system("clear");
    board.ShowBoard();
    if (board.CheckWin()) {
      break;
    }
  }
  
  system("clear");
  Congr_window(move_counter);
}