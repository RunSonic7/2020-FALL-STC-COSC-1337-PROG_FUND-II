/* Filename: AccountTest.cpp
   Title:  Account Test v2
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Date: Saturday, September 5, 2020
   Due: Sunday, September 6, 2020
   Notes: Figure 3.8, compiled with g++ -std=c++11 
*/

#include <iostream>
#include "Account.h"

using namespace std;

int main() 
{
    
    Account account1("Jane Green", 50);
    Account account2("John Blue", -7);

    // Display the initial balance of each object
    cout << "account1: " << account1.getName() << " balance is $" << account1.getBalance();
    cout << "\naccount2: " << account2.getName() << " balance is $" << account2.getBalance();

    cout << "\n\nEnter deposit amount for account1: ";  // prompt
    int depositAmount;
    cin >> depositAmount;   // obtain user input
    cout << "adding " << depositAmount << " to account1 balance";
    account1.deposit(depositAmount);    // add to account 1

    // display balances
    cout << "\n\naccount1: " << account1.getName() << " balance is $" << account1.getBalance();
    cout << "\naccount2: " << account2.getName() << " balance is $" << account2.getBalance();

    cout << "\n\nEnter deposit amount for account2: ";  // prompt
    cin >> depositAmount;   // obtain user input
    cout << "adding " << depositAmount << " to account2 balance";
    account2.deposit(depositAmount);    // add to account 2

    // display balances
    cout << "\n\naccount1: " << account1.getName() << " balance is $" << account1.getBalance();
    cout << "\naccount2: " << account2.getName() << " balance is $" << account2.getBalance() << endl;
}