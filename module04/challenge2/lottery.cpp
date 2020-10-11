/* Filename: lottery.cpp
   Title:  Lucky Number Lottery Determinator
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, October 4, 2020
   Notes: (This next problem is not in this book but there is an example of 
          using the binary search with the array class)

          Use the class array to store the numbers of 10 five-digit "lucky" 
          combinations tickets.  Write a program that initializes the class 
          array with the numbers of these 10 lucky combination tickets and then
          lets the player enter this week's winning five-digit number. The
          program should perform a binary search through the list of the
          player's numbers and report whether or not one of the tickets is a
          winner this week. Here are the numbers:

          26791 26792 33445 55555 62483 77777 79422 85647 93121
*/

#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <algorithm> // Contains sort and binary_search
#include "Validation.h"
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