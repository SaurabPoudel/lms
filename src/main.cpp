
#include "../include/User.hpp"
#include "../include/Utils.hpp"
#include <iostream>
#include <string>

using namespace std;

User::User(string name, string password)
{
  this->name = name;
  this->password = password;
}

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
