/* Filename: Date.h
   Title:  Date class definition; Member functions defined in Date.cpp
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, October 25, 2020
   Notes: Date class definition; Member functions defined in Date.cpp
*/

#include <string>

#ifndef DATE_H
#define DATE_H

class Date
{
public:
    static const unsigned int monthsPerYear = 12;   // months in a year
    explicit Date(unsigned int = 1, unsigned int = 1, unsigned int = 1900);
    std::string toString() const;   // date string in month/day/year format
    ~Date();    // provided to confirm destruction order

private:
    unsigned int month; // 1-12 (January-December)
    unsigned int day;   // 1-31 based on month
    unsigned int year;  // any year

    // utility function to check if day is proper for month and year
    unsigned int checkDay(int) const;
};

#endif