#ifndef Book_hpp
#define Book_hpp

#include <string>
using namespace std;

class Book
{
private:
    unsigned int id;
    std::string title;
    std::string author;
    unsigned int year;
    bool isBorrow;

public:
    // Constructor
    Book(unsigned int id, const std::string &title, const std::string &author, unsigned int year, bool isBorrow)
        : id(id), title(title), author(author), year(year), isBorrow(isBorrow) {}

    // Member function to add a book
    static void addBook();

private:
    // Helper function to get the last book ID from the file
    static unsigned int getLastBookID(const std::string &filename);
};

#endif
