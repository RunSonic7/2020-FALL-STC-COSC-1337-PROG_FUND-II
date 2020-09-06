/* Filename: Account.h
   Title:  
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Date: Saturday, September 5, 2020
   Due: Sunday, September 6, 2020
   Notes: Figure 3.4
*/

#include<string>

class Account {
   public:
      // constructor initializes data member name with parameter accountName
      explicit Account(std::string accountName)
         : name(accountName) {  // member initializer
            // empty body
         }

      // function to set the account name
      void setName(std::string accountName) 
      {
         name = accountName;
      }

      // function to retreive the account name
      std::string getName() const
      {
         return name;
      }

      private:
         std::string name; // account name data member
}; // end class Account

