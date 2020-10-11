/* Filename: Validation.h
   Title:  Implementation File for Validation.h
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, October 4, 2020
   Notes: for file lottery.cpp
*/

#include <iostream>
#include <array>
#include <typeinfo>
#include <sstream>

class Validation
{
private:
   std::string userInput;
   bool isNumber = false;
   int userInputCast;

public:
    void validateInput(std::string);
    bool checkIfNumber(std::string);

    void setUserInput(std::string input)
    {  userInput = input;  }

   int getUserInput()
   {  return userInputCast;  }

   void castToInt(std::string input)
   {  userInputCast = stoi(input);  }

   bool getIsNumber()
   {  return isNumber;  }
};

void Validation::validateInput(std::string input)
   {

      setUserInput(input);                 // Set member variable to input of user
      isNumber = checkIfNumber(userInput); // Check if what user input is a number or not
      
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


// Source for isNumber Code
// https://www.geeksforgeeks.org/program-check-input-integer-string/
// Resources
// https://www.geeksforgeeks.org/converting-strings-numbers-cc/