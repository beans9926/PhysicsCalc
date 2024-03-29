// This file is everything that we need to calculate the centre of mass of a
// barycentric system. the two most important variables ( mass & position ) are
// defined and initialized in a struct com() function does the job of taking in
// inputs and outputting the answers

//"-0" from what i know, is not a real number but is a thing in c++
// that is the reason -0 is needed as input if the value for a variable is
// unknown

#include <iostream>
#include <numeric>
#include <vector>

// structure for two variables in the centre of mass formula
struct {
  long double cenOfMass;
  std::vector<long double> *mass = new std::vector<long double>;
  std::vector<long double> *position = new std::vector<long double>;
} formula;

// function for data input & output
void com() {
  int type = 0;
  int objCount = 0;
  long double *c{&formula.cenOfMass};

  std::cout << "\nCalculate Centre of Mass of a 2-object/Barycentric system";
  std::cout << "\nEnter the number of objects: ";
  std::cin >> objCount; // number of objects in the system

  long double input;
  for (int i = 0; i < objCount; i++) {
    std::cout << "Mass for object " << i + 1 << " = ";
    std::cin >> input;
    formula.mass->push_back(input); // input gets overwritten and gets pushed
                                    // into respective vectors

    std::cout << "Position of object = ";
    std::cin >> input;
    formula.position->push_back(input);
  }

  long double inter = 0.0;

  // the formula includes dividing by the summation of all the masses in the
  // system the if statement below checks whether the summation of all masses in
  // the system (values stored in a vector defined in the struct) is not zero.
  // if it is zero, it breaks out of the code

  if ((std::accumulate(formula.mass->begin(), formula.mass->end(), 0)) == 0) {
    std::cout << "Division by zero!" << std::endl;
    return;
  }

  // inter = shorthand for intermediary
  // represents the summation of all m(n)*x(n) as per the formula
  for (int j = 0; j < objCount; j++) {
    inter += (formula.mass->at(j) * formula.position->at(j));
  }
  *c = inter / (std::accumulate(formula.mass->begin(), formula.mass->end(), 0));
  std::cout << "\nThe centre of mass for the system is = " << *c << std::endl;

  return;
}
