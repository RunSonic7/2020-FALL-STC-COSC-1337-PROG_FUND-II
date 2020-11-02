/* Filename: Employee.cpp
   Title:  Employee class member-function definitions.
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, October 25, 2020
   Notes: Employee class member-function definitions.
*/

#include <iostream>
#include <sstream>
#include "Employee.h" // Employee class definition
#include "Date.h" // Date class definition
using namespace std;

// constructor uses member initializer list to pass initalizer
// values to constructors of member objects
Employee::Employee(const string& first, const string& last, const Date &dateOfBirth, const Date &dateOfHire)
    : firstName{ first },
    lastName{ last },
    birthDate{ dateOfBirth },
    hireDate{ dateOfHire }
{
    // output Employee object to show when constructor is called
    cout << "Employee object constructor: " << firstName << ' ' << lastName << endl;
}

// print Employee object
string Employee::toString() const 
{
    ostringstream output;
    output << lastName << ", " << firstName << " Hired: " << hireDate.toString() << " Birthday: " << birthDate.toString();

    return output.str();
}

// output Employee object to show when its destructor is called
Employee::~Employee()
{
    cout << "Employee object destructor: " << lastName << ", " << firstName << endl;
}