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

    do
    {
        cout << "How many test scores do you have to input? \n";
        cin >> size;
        gradeBook.validateInput(size);

    } while (gradeBook.getIsValidInput() == false);

    // Create Gradebook Array via pointer
    gradeBook.createGradebookArray();

    // As user to enter test scores;
    for (int index = 0; index < gradeBook.getGradeBookSize(); index++) {
        cout << "Enter grade number " << (index + 1) << ": ";
        cin >> gradeBook.testScores[index];
    }

    // Display grades and average to user;
    gradeBook.displayData();

    gradeBook.~GradeBook();
}
