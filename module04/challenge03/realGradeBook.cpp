/* Filename: realGradeBook.cpp
   Title:  Case Study GradeBook class modified with struct StudentInfo
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, October 4, 2020
   Notes: Modify the case study in section 7.6 (the class Gradebook) to have the
          class array store a structure (struct) that will include a name that
          you either initialize or enter from the keyboard (not sorted). 

          struct studentInfo{
            std::string studentName;
            int grade;
          };

          Use the built-in sort of the class array to display the names in
          alphabetical order when you are displaying the student grades. My
          recommendation, is to compile and make 7.6 run as shown in the book.
          Then add the structure and modify the code to complete this challenge.
*/

#include <array>
#include "GradeBook.h" // GradeBook class  definition
using namespace std;

int main()
{
   // array of student grades
   const array<int, GradeBook::students> grades{
       87, 68, 94, 100, 83, 78, 85, 91, 76, 87};
   // Array of student names
   const array<string, GradeBook::students> studentNames{
       "Ben", "Kristina", "Ivan", "Pablo", "Juan", "Mark", "Jesus", "Luis", "Bernie", "Jose"};
   //const int grades[GradeBook::students] = {87, 68, 94, 100, 83, 78, 85, 91, 76, 87};
   //const string names[GradeBook::students] = {"Ben", "Kristina", "Ivan", "Pablo", "Juan", "Mark", "Jesus", "Luis", "Bernie", "Jose"};

   string courseName{"CS101 Introduction to C++ Programming"};
   GradeBook myGradeBook(courseName, grades, studentNames);
   myGradeBook.displayMessage();
   myGradeBook.processGrades();

   myGradeBook.processData();
   sort(myGradeBook.studentInfo, myGradeBook.studentInfo + 10, compareNames);

   for (int i = 0; i < 10; i++)
   {
      cout << myGradeBook.studentInfo[i].studentName << "\t\t" << myGradeBook.studentInfo[i].grade << "\t\t"
           << endl;
   }
}

// References:
// https://www.geeksforgeeks.org/structure-sorting-in-c/