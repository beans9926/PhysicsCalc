#include <cmath>
#include <iostream>
#include "kinematics.h"
#include "printingUtils.h"
#include "error.h"

struct varKinematicEquation{
  double finalVelocity;
  double initialVelocity; 
  double acceleration;
  double displacement;
  double timeInterval;
} v_equ;



double& a = v_equ.acceleration;
double& t = v_equ.timeInterval;
double& u = v_equ.initialVelocity;
double& v = v_equ.finalVelocity;
double& s = v_equ.displacement;



void findFinalVel(int);
void findInitVel(int);
void findAccel(int);
void findTime(int);
void findDisp(int);



void inputAcceleration(void){
  std::cout << "\nAcceleration: ";
  std::cin >> a;
  return;
}

void inputTime(void){
  std::cout << "\nTime: ";
  std::cin >> t;
  return;
}

void inputInitVel(void){
  std::cout << "\nInitial Velocity: ";
  std::cin >> u;
  return;
}

void inputFinalVel(void){
  std::cout << "\nFinal Velocity: ";
  std::cin >> v;
  return;
}

void inputDisplacement(void){
  std::cout << "\nDisplacement: ";
  std::cin >> s;
  return;
}



void kinematicEquationSelector(){
  regularTitleCard();

  short int selection;
  
  std::cout << "u => Initial velocity \n";
  std::cout << "v => Final velocity   \n";
  std::cout << "a => Acceleration     \n";
  std::cout << "s => Displacement     \n";
  std::cout << "t => Time interval    \n\n";

  std::cout << "Choose a value to be found:\n";
  std::cout << "1 -- Final Velocity   (v) \n";
  std::cout << "2 -- Initial Velocity (s) \n";
  std::cout << "3 -- Acceleration     (u) \n";
  std::cout << "4 -- Time             (a) \n";
  std::cout << "5 -- Displacement     (t) \n";

  std::cin >> selection;
  
  std::cout << "What parameters are available? \n";

  switch (selection) {
    case 1:
      regularTitleCard();
      std::cout << "1. u, a, t \n";
      std::cout << "2. u, a, s \n";
      std::cout << "3. s, t \n";
      std::cin >> selection;
      findFinalVel(selection);
      break;
    case 2:
      regularTitleCard();
      std::cout << "1. s, t, a \n";
      std::cout << "2. v, a, t \n";
      std::cout << "3. v, a, s \n";
      std::cout << "4. s, t";
      std::cin >> selection;
      findInitVel(selection);
      break;
    case 3:
      regularTitleCard();
      std::cout << "1. s, u, t \n";
      std::cout << "2. v, u, t \n";
      std::cout << "3. v, u, s \n";
      std::cin >> selection;
      findAccel(selection);
      break;
    case 4:
      regularTitleCard();
      std::cout << "1. v, u, a \n";
      std::cout << "2. s, v/u \n";
      std::cin >> selection;
      findTime(selection);
      break;
    case 5:
      regularTitleCard();
      std::cout << "1. u, t, a \n";
      std::cout << "2. v, u, a \n";
      std::cin >> selection;
      findDisp(selection);
      break;
    default:
      errorInputCall();
      kinematicEquationSelector();
  }
}



void findFinalVel(int selection){
  //jfdsfrksjgl;
  regularTitleCard();

  if (selection == 1) {
    inputInitVel();
    inputAcceleration();
    inputTime();

    v = u + (a * t);
    regularTitleCard();
    std::cout << "\nFinal Velocity = " << v << std::endl;
  }

  else if (selection == 2) {
    inputAcceleration();
    inputInitVel();
    inputDisplacement();

    v = sqrt((u*u) + (2*a*s));
    regularTitleCard();
    std::cout << "\nFinal Velocity = " << v << std::endl;

  }

  else if (selection == 3) {
    inputDisplacement();
    inputTime();

    v = s/t;
    regularTitleCard();
    std::cout << "\nFinal Velocity = " << v << std::endl;
  }

  else{
    errorInputCall();
    kinematicEquationSelector();
  }
}



void findInitVel(int selection){
  //hdsklahglk;
  regularTitleCard();

  if(selection == 1){
    inputDisplacement();
    inputAcceleration();
    inputTime();

    u = (s - ((1/2.0f) * a * (t * t)))/t;
    std::cout << "\nInitial Velocity = " << u << std::endl;
  }

  else if (selection == 2) {
    inputFinalVel();
    inputAcceleration();
    inputTime();

    u = v - (a * t);
    std::cout << "\nInitial Velocity = " << u << std::endl;
  }

  else if (selection == 3){
    inputFinalVel();
    inputAcceleration();
    inputDisplacement();

    u = sqrt((v * v) - (2 * a * s));
    std::cout << "\nInitial Velocity = " << u << std::endl;
  }

  else if (selection == 4){
    inputDisplacement();
    inputTime();

    u = s/t;
    std::cout << "\nInitial Velocity = " << u << std::endl;
  }

  else{
    errorInputCall();
    kinematicEquationSelector();
  }
}

void findAccel(int selection){
  //jfkdslg;
  regularTitleCard();

  if(selection == 1){
    inputDisplacement();
    inputInitVel();
    inputTime();

    a = 2 * (s - (u * t))/(t * t);
    std::cout << "\nAcceleration = " << a << std::endl;
  }

  else if (selection == 2){
    inputFinalVel();
    inputTime();
    inputInitVel();

    a = (v - u)/t;
    std::cout << "\nAcceleration= " << a << std::endl;
  }

  else if (selection == 4){
    inputDisplacement();
    inputInitVel();
    inputFinalVel();

    a = ((v*v)-(u*u))/2*a;
    std::cout << "\nAcceleration= " << a << std::endl;
  }

  else{
    errorInputCall();
    kinematicEquationSelector();
  }
}



void findTime(int selection){
  //klfjdsklshf;
  regularTitleCard();

  if(selection == 1){
    inputFinalVel();
    inputInitVel();
    inputAcceleration();

    t = (v - u)/a;
    std::cout << "\nTime = " << t << std::endl;
  }

  else if (selection == 2){
    inputDisplacement();
    inputFinalVel();

    t = s/v;
    std::cout << "\nTime = " << t << std::endl;
  }

  else{
    errorInputCall();
    kinematicEquationSelector();
  }
}



void findDisp(int selection){
  //jfkdlls;
  regularTitleCard();

  if(selection == 1){
    inputInitVel();
    inputTime();
    inputAcceleration();

    s = (u * t) + ((1/2.0f) * a * (t * t));
    std::cout << "\nDisplacement = " << s << std::endl;
  }

  else if (selection == 2){
    inputFinalVel();
    inputInitVel();
    inputAcceleration();

    s = ((v * v) - (u * u)) / (2 * a);
    std::cout << "\nDisplacement = " << s << std::endl;
  }

  else{
    errorInputCall();
    kinematicEquationSelector();
  }
}

