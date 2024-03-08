#define User_hpp
#ifdef User_hpp

#include <string>
using namespace std;

class User
{
private:
  string name;
  string id;
  string password;

public:
  User(string name, string id, string password);
  void burrowBook(string bookName);
  void returnBook(string bookName);
  void displayUser();
};
class Librarian : public User
{
public:
  Librarian(string name, string id, string password);
  void addBook(string bookName, string author, string genre, string publisher,
               int year, int copies);
  void editBook(string bookName, string author, string genre, string publisher,
                int year, int copies);
};

#endif
