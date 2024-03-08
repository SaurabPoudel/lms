#include <iostream>

#include "../include/Auth.hpp"
#include "../include/Book.hpp"

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_BLUE "\x1b[34m"

#ifdef _WIN32
#include <stdlib.h>
#else
#include <cstdlib>
#endif

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

         // case 3:
         //   issueBook();
         //   break;

         // case 4:
         //   returnBook();
         //   break;

         // case 5:
         //   searchBooks();
         //   break;

         // case 6:
         //   searchMember();
         //   break;

         // case 7:
         //   displayBooks();
         //   break;

         // case 8:
         //   displayMembers();
         //   break;

      default:
         std::cout << ANSI_COLOR_RED "\nPlease enter valid  key" ANSI_COLOR_RESET;

         return;
      }
   }
}
