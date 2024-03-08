
#include "../include/User.hpp"
#include "../include/Utils.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
  clearScreen();
  printBanner();
  pressEnterToContinue();
  clearScreen();
  menuBar();
  prompt();
  return 0;
}
