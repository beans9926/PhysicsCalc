#include <iostream>
#include <vector>

struct {
  unsigned int timeSecStart;
  unsigned int timeSecEnd;
  unsigned int accuracyRect;
  unsigned int highPowerEqu;
  std::vector<int> *coefficients = new std::vector<int>;
  std::vector<long double> *integFuncSummation = new std::vector<long double>;
} velEqu;
