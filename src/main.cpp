
#include "../include/User.hpp"
#include "../include/Utils.hpp"
#include <iostream>
#include <string>

using namespace std;

User::User(string name, string id, string password) {
  this->name = name;
  this->id = id;
  this->password = password;
}

void User::displayUser() {
  cout << "Name: " << name << endl;
  cout << "ID: " << id << endl;
  cout << "Password: " << password << endl;
}

int main() {
  User user("John Doe", "johndoe", "password");
  user.displayUser();
  clearScreen();
  printBanner();
  pressEnterToContinue();
  clearScreen();
  menuBar();
  prompt();
  return 0;
}
