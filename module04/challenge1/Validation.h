/* Filename: Validation.h
   Title:  Implementation File for Validation.h
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, October 4, 2020
   Notes: for file dupElimArray.cpp
*/

#include <iostream>
#include <array>
#include <typeinfo>
#include <sstream>

class Validation
{
private:
   std::string userInput;
   bool isValidInput = false;
   bool isNumber = false;
   bool isInRange = false;
   int userInputCast;

public:
   void validateInput(std::string);
   bool checkIfNumber(std::string);
   bool checkRange(int);

   void setIsValidInput(bool tf)
   {  isValidInput = tf;  }

   bool getIsValidInput()
   {  return isValidInput;  }

   void setUserInput(std::string input)
   {  userInput = input;  }

   int getUserInput()
   {  return userInputCast;  }

   void castToInt(std::string input)
   {  userInputCast = stoi(input);  }
};

void Validation::validateInput(std::string input)
   {

      setUserInput(input);                 // Set member variable to input of user
      isNumber = checkIfNumber(userInput); // Check if what user input is a number or not

      if (isNumber)
      {
         isInRange = checkRange(userInputCast);

         if (isInRange)
         {
            setIsValidInput(true);
         }
         else
         {
            std::cout << "Your input is out of range.\nPlease enter a value between 1 and 20.\n\n";
            setIsValidInput(false);
         }
      }
      else
      {
         std::cout << "Your input is invalid. Please re-enter a valid entry.\n";
         setIsValidInput(false);
      }
   }

bool Validation::checkIfNumber(std::string input)
   {
      // Check each character. Once false, loop breaks
      for (int i = 0; i < input.length(); i++)
      {
         if (isdigit(input[i]) == false)
         {
            return false;
         }
      }
      castToInt(input); // Since number, cast to int type
      return true;
   };

bool Validation::checkRange(int num)
   {
      if (num >= 1 && num <= 20)
         return true;
      else
         return false;
   }
// Source for isNumber Code
// https://www.geeksforgeeks.org/program-check-input-integer-string/
// Resources
// https://www.geeksforgeeks.org/converting-strings-numbers-cc/