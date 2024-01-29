#include <iostream>
#include <numeric>
#include <vector>

struct {
  long double cenOfMass;
  std::vector<long double> *mass = new std::vector<long double>;
  std::vector<long double> *position = new std::vector<long double>;
} formula;

void com() {
  int type = 0;
  int objCount = 0;
  long double *c{&formula.cenOfMass};

  std::cout << "Calculate Centre of Mass of a 2-object/Barycentric system \n";
  std::cout << "Enter the number of objects: \n";
  std::cin >> objCount;

  std::cout << "Enter the values ( '-0' if to be found ) \n";

  long double input;
  for (int i = 0; i < objCount; i++) {
    std::cout << "Mass for object " << i + 1 << " = ";
    std::cin >> input;
    formula.mass->push_back(input);

    std::cout << "Position of object = ";
    std::cin >> input;
    formula.position->push_back(input);
  }

  long double inter = 0.0;

  if ((std::accumulate(formula.mass->begin(), formula.mass->end(), 0)) == 0) {
    std::cout << "Division by zero!" << std::endl;
    return;
  }
  //  *c = (((*m1) * (*p1)) + ((*m2) * (*p2))) / (*m1 + *m2);
  for (int j = 0; j < objCount; j++) {
    inter += (formula.mass->at(j) * formula.position->at(j));
  }
  *c = inter / (std::accumulate(formula.mass->begin(), formula.mass->end(), 0));
  std::cout << "The centre of mass is = " << *c << std::endl;
}
