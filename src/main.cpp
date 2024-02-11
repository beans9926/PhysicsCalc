#include "avgVel.h"
#include "com.h"
#include "printingUtils.h"
#include <iostream>


int main() {

  welcomeTitleCard();

  std::cout << "\nEnter your choice:";
  std::cout << "\n1. Centre of mass (Barycentric system)";
  std::cout << "\n2. Average velocity of an object (equation of velocity wrt. "
               "time needed)";
  std::cout << "\n0. Exit Program\n";

  int inputInteger;
  std::cin >> inputInteger;

  switch (inputInteger) {
  case 1:
    regularTitleCard();
    com();
    break;
  case 2:
    regularTitleCard();
    chooseCalculationType();
    break;
  case 0:
    std::cout << "\nExiting... ";
    break;
  default:
    std::cout << "\nOther symbols/characters were entered!";
    break;
  };

  return 0;
}
