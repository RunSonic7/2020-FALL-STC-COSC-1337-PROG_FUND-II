// main.cpp
// Demonstrating class PhoneNumber's overloaded stream inserting
// and stream extraction operations. 
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