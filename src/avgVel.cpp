// Code for calculating the average velocity of an object
// This is done with using an equation that represents the velocity of an object
// and calculating the area under that curve using trapezoidal rule

#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
#include "printingUtils.h"



void inputParamTrapezoidalAvgVel();
void inputParamDivDistanceTime();
void trapezoidalAverageVelocity();
void divisionalAverageVelocity();




struct {
  float timeSecondsStart;
  float timeSecondsEnd;
  unsigned int accuracyInRectangles;
  unsigned int highestPowerEquation;
  long double deltaX;                       // deltaX is the length of the subinterval
  long double integralCalculation = 0.0;    // used for calculation of area of the subintervals
  long double averageVelocity = 0.0;

  std::vector<int> *coefficients = new std::vector<int>;
  std::vector<long double> *integFuncSummation = new std::vector<long double>;


  // variables for distance time parameters
  long double divChangeInPosition;
  long double divChangeInTime;
} velEqu;


void chooseCalculationType(){

  std::cout << "\n\nChoose the type of parameters you have:";
  std::cout << "\n 1. Change in position & Duration of period"; 
  std::cout << "\n 2. Equation of velocity, Duration of period\n";

  short int calcType;
  std::cin >> calcType;

  switch (calcType) {
    case 1:
      regularTitleCard();
      inputParamDivDistanceTime();
      break;
    case 2:
      regularTitleCard();
      inputParamTrapezoidalAvgVel();
      break;
    default:
      std::cout << "\nUndefined choice! Try again!";
      regularTitleCard();
      chooseCalculationType();
      break;
  }
}


void inputParamDivDistanceTime(){
  std::cout << "\nEnter the change in position: ";
  std::cin >> velEqu.divChangeInPosition;

  std::cout << "\nEnter the change in time: ";
  std::cin >> velEqu.divChangeInTime;
  
  divisionalAverageVelocity();
}


void inputParamTrapezoidalAvgVel() {

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

  trapezoidalAverageVelocity();
}


void divisionalAverageVelocity(){
  std::cout << "\n\nThe Average Velocity of the object is = " 
    << velEqu.divChangeInPosition / velEqu.divChangeInTime;
}


void trapezoidalAverageVelocity() {
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
