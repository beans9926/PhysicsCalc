#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

struct {
  float timeSecondsStart;
  float timeSecondsEnd;
  unsigned int accuracyInRectangles;
  unsigned int highestPowerEquation;
  long double deltaX;
  long double integralCalculation = 0.0;
  long double averageVelocity = 0.0;

  std::vector<int> *coefficients = new std::vector<int>;
  std::vector<long double> *integFuncSummation = new std::vector<long double>;
} velEqu;

void avgVel() {
  std::cout << "Part for entering the equation and other required inputs, read "
               "intructions carefully";
  std::cout << "\nEnter the highest power of the equation (+ve integers only)";
  std::cin >> velEqu.highestPowerEquation;

  int input;
  for (int i = velEqu.highestPowerEquation; i >= 0; i--) {
    std::cout << "\nEnter coefficient of term with power " << i << " :";
    std::cin >> input;
    velEqu.coefficients->push_back(input);
  }

  std::cout << "Enter start time (in seconds): ";
  std::cin >> velEqu.timeSecondsStart;

  std::cout << "Enter end time ( in seconds ): ";
  std::cin >> velEqu.timeSecondsEnd;

  std::cout << "Enter accuracy value: ";
  std::cin >> velEqu.accuracyInRectangles;

  velEqu.deltaX = (velEqu.timeSecondsEnd - velEqu.timeSecondsStart) /
                  velEqu.accuracyInRectangles;
  std::cout << velEqu.deltaX;

  long double a;
  for (int i = 0; i <= velEqu.accuracyInRectangles; i++) {
    a = 0.0;
    velEqu.integralCalculation = 0.0;
    for (int j = velEqu.highestPowerEquation; j >= 0; j--) {
      a = pow(static_cast<float>(
                  (velEqu.timeSecondsStart + (i * velEqu.deltaX))),
              static_cast<float>(j)) *
          velEqu.coefficients->at(velEqu.highestPowerEquation - j);
      // std::cout << "\n" << a;
      velEqu.integralCalculation += a;
    }
    if (i == 0 || i == velEqu.accuracyInRectangles) {
      velEqu.integralCalculation *= 1;
    } else {
      velEqu.integralCalculation *= 2;
    }

    velEqu.integFuncSummation->push_back(velEqu.integralCalculation);
    std::cout << "\n" << velEqu.integralCalculation;
  }

  velEqu.integralCalculation = (std::accumulate(
      velEqu.integFuncSummation->begin(), velEqu.integFuncSummation->end(), 0));

  std::cout << "\n\n" << velEqu.integralCalculation;

  velEqu.averageVelocity = ((velEqu.deltaX * velEqu.integralCalculation) / 2) /
                           (velEqu.timeSecondsEnd - velEqu.timeSecondsStart);

  std::cout << "\nThe average velocity of the object is = "
            << velEqu.averageVelocity << std::endl;

  return;
}
