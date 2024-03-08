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
    Book(unsigned int id, const std::string &title, const std::string &author, unsigned int year, bool isBorrow)
    {
        this->id = id;
        this->title = title;
        this->author = author;
        this->year = year;
        this->isBorrow = isBorrow;
    }

    static void addBook();
    static void searchBook();
    void editBook();
    void deleteBook();
    static void displayBooks();

private:
    // Helper function to get the last book ID from the file
    static unsigned int getLastBookID(const std::string &filename);
};

#endif
