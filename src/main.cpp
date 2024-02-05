#include "avgVel.h"
#include "com.h"
#include <iostream>

int main() {
  system("clear");
  std::cout << "---------------Welcome to DynaCalc!---------------";
  std::cout << "\nEnter your choice:";
  std::cout << "\n1. Centre of mass (Barycentric system)";
  std::cout << "\n2. Average velocity of an object (equation of velocity wrt. "
               "time needed)";
  std::cout << "\n0. Exit Program\n";

  int inputInteger;
  std::cin >> inputInteger;

  switch (inputInteger) {
  case 1:
    com();
    break;
  case 2:
    inputAverageVelocity();
    break;
  case 0:
    std::cout << "\n\nExiting...";
    break;
  default:
    std::cout << "\nOther symbols/characters were entered!";
    break;
  };

  return 0;
}
