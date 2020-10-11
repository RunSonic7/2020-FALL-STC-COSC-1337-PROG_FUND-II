/* Filename: GradeBook.h
   Title:  Implementation file GradeBook.h for realGradeBook.cpp
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, October 4, 2020
   Notes: Fig. 7.13: GradeBook.
          Definition of class GradeBook that uses an array to store test grades.
*/

#include <string>
#include <array>
#include <iostream>
#include <iomanip> // parameterized stream manipulators
#include <algorithm>

// StudentInfo Struct definition
struct StudentInfo
{
   std::string studentName;
   int grade;
};

// GradeBook class definition
class GradeBook
{
public:
   // constant number of students who took the test
   static const size_t students{10}; // note public data
   StudentInfo studentInfo[10];

   // constructor initializes courseName and grades array
   GradeBook(const std::string &name,
             const std::array<int, students> &gradesArray,
             const std::array<std::string, students> &studentNamesArray)
       : courseName{name}, grades{gradesArray}, studentNames{studentNamesArray}
   {
   }

   // Compare structs, static so can be seen in other functions
   static bool compareNames(StudentInfo, StudentInfo);

   void processData(); // Process data into struct and sort

   void displaySortedData(); // Display data to user

   // function to set the course name
   void setCourseName(const std::string &name)
   {  courseName = name;  } // store the course name

   // function to retrieve the course name
   const std::string &getCourseName() const
   {  return courseName;  }

   // display a welcome message to the GradeBook user
   void displayMessage() const;

   // perform various operations on the data (none modify the data)
   void processGrades() const;

   // find minimum grade
   int getMinimum() const;

   // find maximum grade
   int getMaximum() const;

   // determine average grade for test
   double getAverage() const;

   // output bar chart displaying grade distribution
   void outputBarChart() const;

   // output the contents of the grades array
   void outputGrades() const;

private:
   std::string courseName;                         // course name for this grade book
   std::array<int, students> grades;               // array of student grades
   std::array<std::string, students> studentNames; // array of student names;
};

bool GradeBook::compareNames(StudentInfo student1, StudentInfo student2)
{
   if (student1.studentName < student2.studentName)
   {
      return true;
   }
   return false;
}

void GradeBook::processData()
{
   for (size_t i = 0; i < students; i++)
   {
      studentInfo[i].studentName = studentNames[i];
      studentInfo[i].grade = grades[i];
   }
   std::sort(studentInfo, studentInfo + students, compareNames);
}

void GradeBook::displaySortedData()
{
   std::cout << "\nGrades by Name (Sorted)\n\n"
             << "Name" << "\t" << std::setw(11) << "Grade\n"
             << "------------------\n";

   for (size_t index = 0; index < GradeBook::students; index++)
   {
      std::cout << studentInfo[index].studentName << "\t" << std::setw(10)
                << studentInfo[index].grade << std::endl;
   }
}

void GradeBook::displayMessage() const
{
   // call getCourseName to get the name of this GradeBook's course
   std::cout << "Welcome to the grade book for\n"
             << getCourseName()
             << "!" << std::endl;
}

void GradeBook::processGrades() const
{
   outputGrades(); // output grades array

   // call function getAverage to calculate the average grade
   std::cout << std::setprecision(2) << std::fixed;
   std::cout << "\nClass average is " << getAverage() << std::endl;

   // call functions getMinimum and getMaximum
   std::cout << "Lowest grade is " << getMinimum()
             << "\nHighest grade is " << getMaximum() << std::endl;

   outputBarChart(); // display grade distribution chart
}

int GradeBook::getMinimum() const
{
   int lowGrade{100}; // assume lowest grade is 100

   // loop through grades array
   for (int grade : grades)
   {
      // if current grade lower than lowGrade, assign it to lowGrade
      if (grade < lowGrade)
      {
         lowGrade = grade; // new lowest grade
      }
   }

   return lowGrade; // return lowest grade
}

int GradeBook::getMaximum() const
{
   int highGrade{0}; // assume highest grade is 0

   // loop through grades array
   for (int grade : grades)
   {
      // if current grade higher than highGrade, assign it to highGrade
      if (grade > highGrade)
      {
         highGrade = grade; // new highest grade
      }
   }

   return highGrade; // return highest grade
}

double GradeBook::getAverage() const
{
   int total{0}; // initialize total

   // sum grades in array
   for (int grade : grades)
   {
      total += grade;
   }

   // return average of grades
   return static_cast<double>(total) / grades.size();
}

// output bar chart displaying grade distribution
void GradeBook::outputBarChart() const
{
   std::cout << "\nGrade distribution:" << std::endl;

   // stores frequency of grades in each range of 10 grades
   const size_t frequencySize{11};
   std::array<unsigned int, frequencySize> frequency{}; // init to 0s

   // for each grade, increment the appropriate frequency
   for (int grade : grades)
   {
      ++frequency[grade / 10];
   }

   // for each grade frequency, print bar in chart
   for (size_t count{0}; count < frequencySize; ++count)
   {
      // output bar labels ("0-9:", ..., "90-99:", "100:")
      if (0 == count)
      {
         std::cout << "  0-9: ";
      }
      else if (10 == count)
      {
         std::cout << "  100: ";
      }
      else
      {
         std::cout << count * 10 << "-" << (count * 10) + 9 << ": ";
      }

      // print bar of asterisks
      for (unsigned int stars{0}; stars < frequency[count]; ++stars)
      {
         std::cout << '*';
      }

      std::cout << std::endl; // start a new line of output
   }
}

void GradeBook::outputGrades() const
{
   std::cout << "\nThe grades are:\n\n";

   // output each student's grade
   for (size_t student{0}; student < grades.size(); ++student)
   {
      std::cout << studentNames[student] << "\t" << std::setw(2) << student + 1 << ": "
                << std::setw(3) << grades[student] << std::endl;
   }
}
