/* Filename: ClassRoom.h
   Title:  Test 2: Header file

   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, November 22, 2020
   Notes: Header file for Test 2
*/
#include <array>
#include <algorithm>
#include <iomanip>

#ifndef CLASSROOM_H
#define CLASSROOM_H

struct StudentInfo
{
    std::string firstName;
    std::string lastName;
    std::string studentID;
};

class ClassRoom
{
private:
    int numberStudents;
    std::string className;
    StudentInfo* roster = nullptr;

public:
    ClassRoom(int = 5, std::string = "CLAS-0101.X99");

    ~ClassRoom();

    int getNumberStudents();

    std::string getClassName();

    StudentInfo* getRoster();

    void addName(std::string, std::string, std::string, int);

    void findName(std::string);

    void printClassRosterInfo();

    void bubbleSort(StudentInfo*, int);

    void swap(StudentInfo&, StudentInfo&);

    // Overloaded +
    ClassRoom operator+(ClassRoom&);
};

#endif