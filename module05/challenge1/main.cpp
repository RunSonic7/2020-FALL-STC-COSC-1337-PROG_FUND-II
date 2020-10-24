/* Filename: main.cpp
   Title: Test Scores #1

   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, October 18, 2020
   Notes: Write a program that dynamically allocates a built-in array large
          enough to hold a user-defined number of test scores. (Ask the user how
          many grades will be entered and use a dynamic array to store the
          numbers.) Once all the scores are entered, the array should be passed
          to a function that calculates the average score. The program should
          display the scores and average. Use pointer notation rather than array
          notation whenever possible. (Input Validation: Do not accept negative
          numbers for test scores.) Make it a class, call it something like
          gradeholder.  You will need a destructor because you are using dynamic
          arrays.
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
    string size;
    string grade;

    displayTitle(); // Title ASCII Art

    do
    {
        // Ask User 
        cout << "How many test scores do you have to input?  ";
        cin >> size;
        gradeBook.validateInput(size);

    } while (gradeBook.getIsValidInput() == false);

    // Create Gradebook Array via pointer
    gradeBook.setSize();    // Set size of gradebook
    gradeBook.createGradebookArray();

    // As user to enter test scores, validate, reask if invalid, add to dynamic array.
    for (int index = 0; index < gradeBook.getGradeBookSize(); index++)
    {
        do
        {
            cout << "Enter grade number " << (index + 1) << ": ";
            cin >> grade;

            // Validate if grade is valid input
            gradeBook.validateInput(grade);

        } while (gradeBook.getIsValidInput() == false);

        // Store in testScores dynamic array.
        gradeBook.modifyArray(index, stoi(grade));
    }

    // Display grades and average to user;
    gradeBook.displayData();

    // Delete allocated memory
    gradeBook.~GradeBook();
}

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