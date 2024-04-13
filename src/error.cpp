#include <thread>
#include <iostream>

void errorInputCall(){
  std::cout << "\n\nWrong inputs entered, try again";
  std::this_thread::sleep_for(std::chrono::seconds(2));

}
