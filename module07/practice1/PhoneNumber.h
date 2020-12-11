/* Filename: PhoneNumber.h
   Title:  Demonstrating class PhoneNumber's overloaded stream inserting
           and stream extraction operations. 

   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, November 8, 2020
   Notes: PhoneNumber class definition
*/
#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <iostream>
#include <string>

class PhoneNumber {
    friend std::ostream& operator<<(std::ostream&, const PhoneNumber&);
    friend std::istream& operator>>(std::istream&, PhoneNumber&);

    private:
    std::string areaCode; // 3-digit area code
    std::string exchange; // 3-digit exchange
    std::string line; // 4-digit line
};

#endif