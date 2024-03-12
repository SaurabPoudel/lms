#ifndef User_hpp
#define User_hpp

#include <string>
using namespace std;

class User
{
private:
  string name;
  string password;

public:
  User(string name, string password)
  {
    this->name = name;
    this->password = password;
  };
  static void addUser(string name, string password);
  static void issueBook();
  static void returnBook();
  static void searchMember();
  static void displayMembers();
  static void editProfile();
};
// class Librarian : public User
// {
// public:
//   Librarian(string name, string password);
//   void addBook(string bookName, string author, string genre, string publisher,
//                int year, int copies);
//   void editBook(string bookName, string author, string genre, string publisher,
//                 int year, int copies);
// };

#endif
