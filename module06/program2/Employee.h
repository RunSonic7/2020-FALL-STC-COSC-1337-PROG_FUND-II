/* Filename: Employee.h
   Title:  Employee class definition showing composition
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, October 25, 2020
   Notes: Member functions defined in Employee.cpp
*/

#include <string>

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Date.h" // include Date class definition

class Employee
{
public:
    Employee(const std::string&, const std::string&, const Date&, const Date&);
    std::string toString() const;
    ~Employee(); // provided to confirm destruction order

private:
    std::string firstName;  // composition: member object
    std::string lastName; // composition: member object
    const Date birthDate; // composition: member object
    const Date hireDate; // composition: member object
};

#endif