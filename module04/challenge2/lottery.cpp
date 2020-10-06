#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <algorithm> // Contains sort and binary_search

#include "validation.h"
using namespace std;

int main()
{
   // Variables
   Validation data;
   const int MAXWINNINGNUMBERS = 10;
   string userInput;
   array<int, 10> winningNumbers = {13579, 26791, 26792, 33445,
                                    55555, 62483, 77777, 79422,
                                    85647, 93121};
   do
   {  // Ask user for number and validate
      cout << "Enter your 5 Digit lottery number:  ";
      cin >> userInput;
      data.validateInput(userInput);

      if (data.getIsNumber() == false)
      {
         cout << "This is not a valid entry.\n";
      }
   } while (data.getIsNumber() == false);

   // To use binary_search, must first sort
   sort(winningNumbers.begin(), winningNumbers.end());

   // Search if user input matches a winning number
   bool found{binary_search(winningNumbers.begin(), winningNumbers.end(), data.getUserInput())};

   // Display to user if they won or not.  I wouldn't mind a million dollars :)
   if (found == true)
   {
      cout << "\nCongratulations! You Won!!!!!\n";
   }
   else
   {
      cout << "\nToo bad.  That is not a winning number :(\n";
   }

   return 0;
}