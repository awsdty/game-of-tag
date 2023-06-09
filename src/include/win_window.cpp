#include <include/win_window.h>

int Congr_window(int record)
{

  if(record!=0)
  {
    
    std::cout << "\033[33mПоздравляем вы победили! Вы прошли игру за " <<record<< " шагов!\nЖелаете записать свой результат?\033[0m\ny/n\n";
    char choice;
    std::cin>>choice;
    if(choice=='y')
    {
      const std::string FILENAME = "Record.txt";
      std::ofstream file(FILENAME, std::ios::app);
      if (!file.is_open()) {
        file.open(FILENAME);
      }
      const size_t MAX_LENGTH = 10; // максимальная длина строки
      std::string input_str;

      std::cout << "Введите ваше имя (не больше " << MAX_LENGTH << " символов): ";
      std::cin>>input_str;

      if (input_str.length() > MAX_LENGTH) {
        std::cout << "Ошибка ввода: превышено максимальное количество символов" << std::endl;
        return 0; // завершение программы с ошибкой
      }
      file<<input_str<<" "<<record<<std::endl;
      std::cout<<"Ваш результат успешно записан!\n";
      file.close();
    }
    
  }
  
  return 0;
}