#include <iostream>
#include <cstring>

#include "../include/Auth.hpp"
#include "../include/Book.hpp"
#include "../include/User.hpp"

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_BLUE "\x1b[34m"

#ifdef _WIN32
#include <stdlib.h>
#else
#include <cstdlib>
#endif

#define ROT 13

void clearScreen()
{
#ifdef _WIN32
   // Windows
   system("cls");
#else
   // Unix-like systems
   std::cout << "\033[2J\033[1;1H";
#endif
}
void pressEnterToContinue()
{
   std::cout << "Press Enter to continue . . .";
   std::cin.get();
   return;
}
void printBanner()
{
   std::cout << ANSI_COLOR_GREEN "          _____                    _____      "
                                 "                      _____          \n"
             << "         /\\    \\                  /\\    \\                  "
                "        /\\    \\         \n"
             << "        /::\\____\\                /::\\____\\                 "
                "       /::\\    \\        \n"
             << "       /:::/    /               /::::|   |                     "
                "  /::::\\    \\       \n"
             << "      /:::/    /               /:::::|   |                     "
                " /::::::\\    \\      \n"
             << "     /:::/    /               /::::::|   |                     "
                "/:::/\\:::\\    \\     \n"
             << "    /:::/    /               /:::/|::|   |                    "
                "/:::/__\\:::\\    \\    \n"
             << "   /:::/    /               /:::/ |::|   |                    "
                "\\:::\\   \\:::\\    \\   \n"
             << "  /:::/    /               /:::/  |::|___|______            "
                "___\\:::\\   \\:::\\    \\  \n"
             << " /:::/    /               /:::/   |::::::::\\    \\          "
                "/\\   \\:::\\   \\:::\\    \\ \n"
             << "/:::/____/               /:::/    |:::::::::\\____\\        "
                "/::\\   \\:::\\   \\:::\\____\\\n"
             << "\\:::\\    \\               \\::/    / ~~~~~/:::/    /        "
                "\\:::\\   \\:::\\   \\::/    /\n"
             << " \\:::\\    \\               \\/____/      /:::/    /          "
                "\\:::\\   \\:::\\   \\/____/ \n"
             << "  \\:::\\    \\                          /:::/    /            "
                "\\:::\\   \\:::\\    \\     \n"
             << "   \\:::\\    \\                        /:::/    /             "
                " \\:::\\   \\:::\\____\\    \n"
             << "    \\:::\\    \\                      /:::/    /              "
                "  \\:::\\  /:::/    /    \n"
             << "     \\:::\\    \\                    /:::/    /               "
                "   \\:::\\/:::/    /     \n"
             << "      \\:::\\    \\                  /:::/    /                "
                "    \\::::::/    /      \n"
             << "       \\:::\\____\\                /:::/    /                 "
                "     \\::::/    /       \n"
             << "        \\::/    /                \\::/    /                   "
                "     \\::/    /        \n"
             << "         \\/____/                  \\/____/                    "
                "      \\/____/         \n"
             << "                                                               "
                "                     \n" ANSI_COLOR_RESET
             << ANSI_COLOR_RED "}-------{+} Developed by  079BEIAB Prajit, "
                               "Santosh, Sashmin, Saurab {+}-------{\n"
             << "}--------------------{+} github.com/SaurabPoudel/lms "
                "{+}-----------------------{\n" ANSI_COLOR_RESET;
}
void menuBar()
{
   std::cout << "\n";
   std::cout << ANSI_COLOR_GREEN "{1}-- Add Book\n"
             << "{2}-- Add Member\n"
             << "{3}-- Issue Book\n"
             << "{4}-- Return Book\n"
             << "{5}-- Search Book\n"
             << "{6}-- Search Member\n"
             << "{7}-- Display Books\n"
             << "{8}-- Display Members\n"
             << "{9}-- Edit Profile\n"
             << "{99}-- Exit\n" ANSI_COLOR_RESET << "\n";
}

void replaceSpacesWithDashes(std::string &str)
{
   for (unsigned int i = 0; i < str.length(); i++)
   {
      if (str[i] == ' ')
      {
         str[i] = '-';
      }
   }
}
void charFiller(std::string &info, int spaces)
{
   int currentLength = info.length();
   int fillNumber = spaces - currentLength;

   if (fillNumber > 0)
   {
      for (int i = 0; i < fillNumber; i++)
      {
         info += " ";
      }
   }
}
void prompt()
{
   int input;

   while (1)
   {
      std::cout << "\n"
                << ANSI_COLOR_GREEN "> " ANSI_COLOR_RESET;

      std::cin >> input;
      std::cout << "\n";
      switch (input)
      {
      case 99:
         printf(ANSI_COLOR_RED "LMS has been terminated. \n" ANSI_COLOR_RESET);
         exit(0);

      case 1:

         Book::addBook();
         break;

      case 2:
         addMember();
         break;

      case 3:
         User::issueBook();
         break;

      case 4:
         User::returnBook();
         break;

      case 5:
         Book::searchBook();
         break;

      case 6:
         User::searchMember();
         break;

      case 7:
         Book::displayBooks();
         break;

      case 8:
         User::displayMembers();
         break;

      case 9:
         User::editProfile();
         break;

      default:
         std::cout << ANSI_COLOR_RED "\nPlease enter valid  key" ANSI_COLOR_RESET;

         return;
      }
   }
}
void rot13algorithm(char *pwd)
{
   long unsigned int i;
   for (i = 0; i < strlen(pwd); i++)
   {
      if (std::isalpha(pwd[i]))
      {
         if ((pwd[i] >= 'a' && pwd[i] <= 'm') || (pwd[i] >= 'A' && pwd[i] <= 'M'))
         {
            pwd[i] += ROT;
         }
         else
         {
            pwd[i] -= ROT;
         }
      }
   }
}

char *stringToCString(const std::string &str)
{
   char *cstr = new char[str.length() + 1];
   std::strcpy(cstr, str.c_str());
   return cstr;
}
