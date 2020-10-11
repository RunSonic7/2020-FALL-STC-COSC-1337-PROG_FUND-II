/* Filename: dupElimArray.cpp
   Title:  Dupliciation Eliminiation Array
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, October 4, 2020
   Notes: Challenge 1:  (Duplicate Elimination with array) Use a one-dimensional
          array to solve the  following problem. Read in 20 numbers, each of
          which is between 1 to 20.  As each number is read, validate it and
          store it in the array only if it isn't a duplicate of a number already
          read. After reading all the values, display only the unique values
          that the user entered. Provide for the "worst case" in which all 20
          numbers are different. Use the smallest possible array to solve this
          problem.
*/

#include <iostream>
#include <array> // Required for use of arrays
#include <string>
#include "Validation.h"
using namespace std;

int main()
{
   // Variables
   Validation data = Validation();
   const int MAXSIZE = 20; // Array max size
   string userInput;
   array<int, MAXSIZE> n = {0};
   bool isDuplicate;         // Determine if duplicate
   int counter = 0;          // Counter to keep track of overall input
   int arrayIncrementer = 0; // Counter to keep track of array index location

   while (counter < MAXSIZE)
   {
      cout << "Entry " << counter + 1 << endl;
      while (data.getIsValidInput() == false)
      {
         cout << "Please input a number: ";
         cin >> userInput;
         data.validateInput(userInput);
      }

      // Check if duplicate in array
      for (int index = 0; index < arrayIncrementer + 1; index++)
      {
         if (data.getUserInput() == n[index])
         {
            isDuplicate = true;
            break;
         }
         isDuplicate = false;
      }

      // If not a duplicate, add to the array
      if (isDuplicate == false)
      {
         arrayIncrementer++;
         n[arrayIncrementer - 1] = data.getUserInput();
      }

      counter++;
      //cout << counter << endl;
      data.setIsValidInput(false); // Reset valid input.
   }

   // Declare new smallest possible array
   int inputDataFinal[arrayIncrementer];
   int incrementer = 0;

   // Put validated and non-dups into new array
   for (int i = 0; i < MAXSIZE; i++)
   {

      if (n[i] != 0)
      {
         inputDataFinal[incrementer] = n[i];
         incrementer++;
      }
   }

   // Print Array to User
   cout << "\nArray Contents:\n";
   for (int i = 0; i < arrayIncrementer; i++)
   {
      cout << inputDataFinal[i] << " ";
   }

   // Display Array size which would equal incrementer value. 
   cout << "\nArray Size: " << incrementer << endl;

   // Display message if all 20 values are unique, if not end line
   if (arrayIncrementer == 20)
   {
      cout << "\nLooks like all your numbers are different!\n";
   }
   else
   {
      cout << endl;
   }

   return 0;
}