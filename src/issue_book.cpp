#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "../include/Utils.hpp"
#include "../include/User.hpp"
#include "../include/Book.hpp"

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void updateBookStatus(int id, int newStatus)
{
    std::ifstream file_in("./data/books.csv");
    if (!file_in.is_open())
    {
        std::cout << "Error opening file." << std::endl;
        return;
    }

    std::ofstream temp_out("./data/temp.csv");
    if (!temp_out.is_open())
    {
        std::cout << "Error creating temporary file." << std::endl;
        file_in.close();
        return;
    }

    std::string line;
    while (std::getline(file_in, line))
    {
        std::stringstream ss(line);
        std::string token;
        int currentId;
        std::string bookname, authorname, year;
        int isborrow;

        std::getline(ss, token, ',');
        currentId = std::stoi(token);

        std::getline(ss, bookname, ',');
        std::getline(ss, authorname, ',');
        std::getline(ss, year, ',');
        std::getline(ss, token);
        isborrow = std::stoi(token);

        if (currentId == id)
        {
            temp_out << currentId << "," << bookname << "," << authorname << "," << year << "," << newStatus << "\n";
        }
        else
        {
            temp_out << currentId << "," << bookname << "," << authorname << "," << year << "," << isborrow << "\n";
        }
    }

    file_in.close();
    temp_out.close();

    if (std::remove("./data/books.csv") != 0)
    {
        std::cout << "Error deleting original file. Try changing permission of data using 'mingw32-make change-permission-win' command" << std::endl;
        return;
    }

    if (std::rename("./data/temp.csv", "./data/books.csv") != 0)
    {
        std::cout << "Error renaming temporary file. Try changing permission of data using 'mingw32-make change-permission-win'" << std::endl;
        return;
    }
}

void issueBook_here()
{
    int book_id;

    std::cout << "Enter the book id that you want to issue :" << std::endl;
    std::cin >> book_id;
    updateBookStatus(book_id, 1);

    std::cout << "Book with ID " << book_id << " has been marked as borrowed." << std::endl;
}

void User::issueBook()
{
    clearScreen();
    std::cout << ANSI_COLOR_GREEN "-----------Library Management System-----------\n";
    std::cout << "\n------------------Issue Book------------------\n" ANSI_COLOR_RESET;
    int flag = 0;
    User mem("", "");
    char username[20], password[20];
    std::cout << ANSI_COLOR_GREEN "Enter the username:" ANSI_COLOR_RESET;
    std::cin >> username;
    std::cout << ANSI_COLOR_GREEN "Enter the password:" ANSI_COLOR_RESET;
    std::cin >> password;
    rot13algorithm(password);

    std::ifstream fp("./data/members.csv");
    if (!fp.is_open())
    {
        std::cout << "Error, the file doesnot exist" << std::endl;
    }

    std::string line;
    while (std::getline(fp, line))
    {

        std::istringstream iss(line);
        std::getline(iss, mem.name, ',');
        std::getline(iss, mem.password);
        cout << mem.name << " " << mem.password << endl;
        cout << username << " " << password << endl;
        if ((strcmp(stringToChar(mem.name), username) == 0 && strcmp(stringToChar(mem.password), password) == 0))
        {
            flag = 1;
        }
    }
    fp.close();

    if (flag == 1)
        issueBook_here();
    else
        std::cout << "Sorry you're not registered yet:" << std::endl;

    std::cout << ANSI_COLOR_GREEN "\nEnter [Y] to Continue OR [N] to go to Main Menu \n>" ANSI_COLOR_RESET;

    char inputBook;
    std::cin >> inputBook;

    if (inputBook == 'Y' || inputBook == 'y')
    {
        issueBook();
    }
    else
    {
        clearScreen();
        printBanner();
        menuBar();
        prompt();
    }

    std::cout << ANSI_COLOR_RESET;
}
