/* Filename: main.cpp
   Title: Test Scores #2

   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, October 18, 2020
   Notes: Modify the program #1 to allow the user to enter name-score pairs.
          For each student taking a test, the user types a string representing
          the name of the student, followed by an integer representing the
          student's score. (use a structure) Modify the average-calculating
          function so they take arrays of structures, with each structure
          containing the name and score of a single student. In traversing the
          arrays, use pointers notation rather than array indices.
          (myArray->name   or *(myArray).name)
          Make it a class.  You will need a destructor because you are using
          dynamic arrays.
    Credit: ASCII Art Generator http://patorjk.com/software/taag/
*/

#include <iostream>
#include "GradeBook.h"
using namespace std;

void displayTitle();

int main()
{
   // Variables
   GradeBook gradeBook;
   StudentInfo* testScores = nullptr;
   string size;
   string grade;
   string studentName;

   displayTitle(); // Title ASCII Art

   do
   {
      // Ask User 
      cout << "How many test scores do you have to input?  ";
      //size = "2";
      cin >> size;
      gradeBook.validateInputSize(size);

   } while (gradeBook.getIsValidInput() == false);

   // Create Gradebook Array via pointer
   gradeBook.setSize();    // Set size of gradebook
   testScores = gradeBook.createGradebookArray();

   // As user to enter test scores, validate, reask if invalid, add to dynamic array.
   for (int index = 0; index < gradeBook.getGradeBookSize(); index++)
   {
      do
      {
         cin.ignore(); // Flush Buffer
         cout << "\nEnter Student name: ";
         getline(cin, studentName);

         cout << "Enter grade number " << (index + 1) << ": ";
         cin >> grade;

         // Validate if grade is valid input
         gradeBook.validateInputGrade(grade);

      } while (gradeBook.getIsValidInput() == false);

      // Store in testScores dynamic array.
      gradeBook.modifyArray(index, stoi(grade), studentName, testScores);
   }

   // Display grades and average to user;
   gradeBook.displayData(testScores);

   // Delete allocated memory
   delete[] testScores;
   testScores = 0;

   return 0; /* indicates successful termination */
} /* end main */

void displayTitle()
{
   cout << " _____  _                _____                   _       ______                _\n"
      "|_   _|| |              |  __ \\                 | |      | ___ \\              | |   \n"
      "  | |  | |__    ___     | |  \\/ _ __   __ _   __| |  ___ | |_/ /  ___    ___  | | __\n"
      "  | |  | '_ \\  / _ \\    | | __ | '__| / _` | / _` | / _ \\| ___ \\ / _ \\  / _ \\ | |/ /\n"
      "  | |  | | | ||  __/    | |_\\ \\| |   | (_| || (_| ||  __/| |_/ /| (_) || (_) ||   < \n"
      "  \\_/  |_| |_| \\___|     \\____/|_|    \\__,_| \\__,_| \\___|\\____/  \\___/  \\___/ |_|\\_\\"
      "\n\n\n";
}