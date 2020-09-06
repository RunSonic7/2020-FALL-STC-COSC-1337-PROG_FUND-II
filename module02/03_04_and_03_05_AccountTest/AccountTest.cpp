/* Filename: AccountTest.cpp
   Title:  Account Test
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Date: Saturday, September 5, 2020
   Due: Sunday, September 6, 2020
   Notes: Figure 3.5
*/

#include<iostream>
#include "Account.h"

using namespace std;

int main() {
    // create two Account objects
    Account account1("Jane Green");
    Account account2("John Blue");

    // Display initial value of name for each Account
    cout << "account1 name is: " << account1.getName() << endl;
    cout << "account2 name is: " << account2.getName() << endl;
}