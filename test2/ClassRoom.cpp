/* Filename: ClassRoom.cpp
   Title:  Test 2: Implementation file

   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, November 22, 2020
   Notes: Implementation file for Test 2
*/
#include <iostream>
#include "ClassRoom.h"
using namespace std;

ClassRoom::ClassRoom(int num, std::string name)
{
    numberStudents = num;
    className = name;
    roster = new StudentInfo[getNumberStudents()];
}

ClassRoom::~ClassRoom()
{
    delete[] roster;
    roster = 0;
}

int ClassRoom::getNumberStudents()
{
    return numberStudents;
}

std::string ClassRoom::getClassName()
{
    return className;
}

StudentInfo* ClassRoom::getRoster()
{
    return roster;
}

void ClassRoom::addName(std::string first, std::string last, std::string id, int index)
{
    (roster + index)->firstName = first;
    (roster + index)->lastName = last;
    (roster + index)->studentID = id;
}

void ClassRoom::findName(std::string id)
{
    bool isFound = false;
    int i;

    for (i = 0; i < getNumberStudents(); i++)
    {
        if ((roster + i)->studentID == id)
        {
            isFound = true;
            break;
        }
        else
        {
            isFound = false;
        }
    }

    if (isFound == false)
    {
        std::cout << "Student Not Found" << std::endl;
    }
    else
    {
        std::cout << "Match Found\n"
            << "First Name: " << (roster + i)->firstName << std::endl
            << "Last Name: " << (roster + i)->lastName << std::endl;
    }
}

void ClassRoom::printClassRosterInfo()
{
    bubbleSort(roster, getNumberStudents());

    std::cout << "===== Class Roster for " << getClassName() << " =====\nNumber of students enrolled: " << getNumberStudents() << " \n\n" <<
        std::left << std::setw(15) << "Student ID" << std::setw(15) << "First Name" << std::setw(15) << "Last Name" << std::endl;

    // std::cout << std::setw(0);
    for (int i = 0; i < getNumberStudents(); i++)
    {
        std::cout << std::setw(15) << (roster + i)->studentID << std::setw(15) << (roster + i)->firstName << std::setw(15) << (roster + i)->lastName << std::endl;
    }
}

void ClassRoom::bubbleSort(StudentInfo* array, int size)
{
    //array = roster;
    for (int maxElement = size - 1; maxElement > 0; maxElement--)
    {
        for (int index = 0; index < maxElement; index++)
        {
            if (array[index].lastName > array[index + 1].lastName)
            {
                swap(array[index], array[index + 1]);
            }
        }
    }
}

void ClassRoom::swap(StudentInfo& a, StudentInfo& b)
{
    StudentInfo temp = a;
    a = b;
    b = temp;
}

ClassRoom ClassRoom::operator+(ClassRoom& right)
{
    int totalStudents = numberStudents + right.numberStudents;

    ClassRoom combinedRoster = ClassRoom(totalStudents, "Combined Classroom");

    // Populate first Roster into combined list
    for (int i = 0; i < numberStudents; i++)
    {
        *(combinedRoster.getRoster() + i) = *(roster + i);
    }

    // Populate second roster into combined list
    for (int j = numberStudents, k = 0; j < totalStudents; j++, k++)
    {
        *(combinedRoster.getRoster() + j) = *(right.roster + k);
    }
    return combinedRoster;
}