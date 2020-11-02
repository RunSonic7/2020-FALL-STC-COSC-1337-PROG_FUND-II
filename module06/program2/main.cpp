/* Filename: main.cpp
   Title:  Demonstrating composition -- an object with member objects
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, October 25, 2020
   Notes: Demonstrating composition -- an object with member objects
*/

#include <iostream>
#include "Date.h"   // Date class definition
#include "Employee.h"   // Employee class definition
using namespace std;

int main()
{
    Date birth{7, 24, 1949};
    Date hire{3, 12, 1988};
    Employee manager{"Bob", "Blue", birth, hire};

    cout << "\n" << manager.toString() << endl;
}