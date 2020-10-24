/* Filename:
   Title:

   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due:
   Notes:
*/
#include "GradeBook.h"
#include <iostream>
using namespace std;

int main()
{
    GradeBook gradeBook;
    string size;
    string grade;

    do
    {
        cout << "How many test scores do you have to input? \n";
        cin >> size;
        gradeBook.validateInput(size);

    } while (gradeBook.getIsValidInput() == false);

    // Create Gradebook Array via pointer
    gradeBook.setSize();    // Set size of gradebook
    gradeBook.createGradebookArray();

    // As user to enter test scores;
    for (int index = 0; index < gradeBook.getGradeBookSize(); index++) {

        do
        {
            cout << "Enter grade number " << (index + 1) << ": ";

            cin >> grade;

            // Validate if grade is valid input
            gradeBook.validateInput(grade);

        } while (gradeBook.getIsValidInput() == false);

        // Store in testScores dynamic array.
        gradeBook.testScores[index] = stoi(grade);

    }

    // Display grades and average to user;
    gradeBook.displayData();

    gradeBook.~GradeBook();
}
