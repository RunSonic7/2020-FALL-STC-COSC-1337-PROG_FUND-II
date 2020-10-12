/* Filename: 
   Title:  
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: 
   Notes: Create a class called AddressBook. It should be able to store a
          maximum of 50 names and 50 phone numbers (make an array of structures
          in the object or two arrays). It should contain a method called
          addName that will take a name and phone number and add it to the
          address book. There should be a method called findName that will take
          a string for the name and return the phone number if found in the list
          otherwise return “Person Not Found”. The class should have a method
          called display to show all the entries in the address book sorted by
          last name (last name, first name). Create a main function to test your
          class. Inside the main ask for five names and enter them into the
          address book.  In the main, look for one that is in the address book
          and test for a name that is not in the address book. Finally, in the
          main, display the names in the address book.
*/
#include <iostream>
#include "AddressBook.h"
#include "Validation.h"
using namespace std;

int main()
{
   // Variables
   AddressBook addressBook; // Creates AddressBook object
   Validation validation;   // Creates Validation object for user Input
   string firstName;
   string lastName;
   string phoneNo;
   string userInput;

   cout << "    ___       __    __                       ____              __\n"
           "   /   | ____/ /___/ /_______  __________   / __ )____  ____  / /__\n"
           "  / /| |/ __  / __  / ___/ _ \\/ ___/ ___/  / __  / __ \\/ __ \\/ //_/\n"
           " / ___ / /_/ / /_/ / /  /  __(__  |__  )  / /_/ / /_/ / /_/ / ,<\n"
           "/_/  |_\\__,_/\\__,_/_/   \\___/____/____/  /_____/\\____/\\____/_/|_|\n\n";

   do
   {
      do
      {
         cout << "\n+-------------------------+\n"
                 "| ADDRESSBOOK : MAIN MENU |\n"
                 "+-------------------------+\n\n";
         cout << "Select an option from the menu:\n\n"
              << "1 - Add an Entry\n"
              << "2 - Add 5 Entries\n"
              << "3 - Search for a person\n"
              << "4 - Display AddressBook Entries\n"
              << "5 - Exit\n"
              << "Enter option: ";
         cin >> userInput;

         // Validate User Input is an integer and between 1 and 5 inclusive
         validation.validateInput(userInput);

         if (validation.getIsValidEntry() == false)
         {
            cout << "\n*** Your entry is not valid. Please try again.***\n\n";
         }

      } while (validation.getIsValidEntry() == false);

      // Option 1 - Add 1 Entry
      if (validation.getUserInput() == 1)
      {
         validation.setIsValidEntryFalse(); // Resets validation to false
         cout << "\n+-------------------------+\n"
                 "| ADDRESSBOOK : ADD ENTRY |\n"
                 "+-------------------------+\n\n";
         //cout << addressBook.getPositionIndex() << endl; --- DELETE
         // Validate there is still room in the Adress book
         if (addressBook.getPositionIndex() >= AddressBook::MAXSIZE)
         {
            cout << "\nAddress book is full. Only " << AddressBook::MAXSIZE << " entries allowed.\n"
                 << endl;
         }
         // Allow user to add entry.
         else
         {
            cout << "Enter a First name: ";
            cin >> firstName;

            cout << "Enter a Last name: ";
            cin >> lastName;

            cout << "Enter a phone number (any format): ";
            cin >> phoneNo;

            addressBook.addName(firstName, lastName, phoneNo);
         }
      }
      // Option 2 - Add 5 entries
      else if (validation.getUserInput() == 2)
      {
         validation.setIsValidEntryFalse(); // Resets validation to false
         cout << "\n+-----------------------------+\n"
                 "| ADDRESSBOOK : ADD 5 ENTRIES |\n"
                 "+-----------------------------+\n\n";

         // Validate there is still room in the Adress book (Max would be 5 less the MAX SIZE)
         if (addressBook.getPositionIndex() >= AddressBook::MAXSIZE - 5)
         {
            cout << "\nAddress book unable to add 5 more entires. \nOnly "
                 << AddressBook::MAXSIZE << " entries allowed.\nPlease use Option 1 to add more entries."
                 << endl;
         }
         // Allow user to add entry.
         else
         {
            for (size_t index = 0; index < 5; index++)
            {
               cout << "Entry 1:\n";
               cout << "Enter a First name: ";
               cin >> firstName;

               cout << "Enter a Last name: ";
               cin >> lastName;

               cout << "Enter a phone number (any format): ";
               cin >> phoneNo;

               addressBook.addName(firstName, lastName, phoneNo);
            }
         }
      }
      // Option 3 - Search
      else if (validation.getUserInput() == 3)
      {
         cout << "\n+----------------------+\n"
                 "| ADDRESSBOOK : FINDER |\n"
                 "+----------------------+\n\n";

         cout << "Please Enter the requested information\n";

         cout << "Enter a First name: ";
         cin >> firstName;

         cout << "Enter a Last name: ";
         cin >> lastName;

         // Binary Search
         addressBook.searchData(firstName, lastName);

         //cout << addressBook.getIsNameFound() << endl;
      }
      // Option 4 - Dispaly Entire Address Book sorted by last name
      else if (validation.getUserInput() == 4)
      {
         cout << "\n+---------------------------+\n"
                 "| ADDRESSBOOK : ALL ENTRIES |\n"
                 "+---------------------------+\n\n";

         addressBook.sortData();
         addressBook.displayAllEntries();
      }
      else
      {
         cout << "Address Book closed.\n";
      }

      //validation.setIsValidEntryFalse();  // Reset valid entry to false
   } while (validation.getUserInput() != 5);

   return 0;
}
