/* Filename: Account.h
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

#include<string>

class Account {
    public:
        // Account constructor with two parameters
        Account(std::string accountName, int initialBalance) 
            : name(accountName) { // assign accountName to data member name
      
            // Validate that the initialBalance is greater than 0; if not,
            // data member balance keeps its default initial value of 0
            if (initialBalance > 0) { // if the initialBalance is valid
                balance = initialBalance;        
            }
        }

        // function that deposits (add) onlly a valid amount to the balance
        void deposit(int depositAmount) {
            if (depositAmount > 0) {  // if the depositAmount is valid
                balance = balance + depositAmount;
            }
        }

        // Function that returns the account balance
        int getBalance() const {
            return balance;
        }

        // Function that sets the name
        void setName(std::string accountName) {
            name = accountName;
        }

        // Function that returns the name
        std::string getName() const {
            return name;
        }

        private:
            std::string name;   // account name data member
            int balance = 0;     // data member with default initial value
}; // end class Account

