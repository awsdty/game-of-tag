#include <include/swap.h>

void Swap(int &first, int &second) {
  int temp = first;
  first = second;
  second = temp;
}