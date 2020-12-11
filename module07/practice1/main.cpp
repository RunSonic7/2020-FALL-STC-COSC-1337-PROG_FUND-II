/* Filename: main.cpp
   Title:  Demonstrating class PhoneNumber's overloaded stream inserting
           and stream extraction operations. 

   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, November 8, 2020
   Notes:
*/
#include <iostream>
#include "PhoneNumber.h"
using namespace std;

int main()
{
    PhoneNumber phone; // create object phone

    cout << "Enter phone number in the form (555) 555-5555:" << endl;

    // cin >> phone invoes operator >> by implicity issuing 
    // the non-memeber fuction call operator>>(cin, phone)
    cin >> phone;

    cout << "\nThe phone number entered was:\n";

    // cout << phone invokes operator<< by implicity issuing
    // the non-member function call operator<<(cout, phone)
    cout << phone << endl;
    return 0;
}