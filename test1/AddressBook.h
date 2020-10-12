/* Filename: AddressBook.h
   Title:  Implementation file AddressBook.h for testAddressBook.cpp
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, October 11, 2020
   Notes: Implementation file AddressBook.h for testAddressBook.cpp
*/
#include <iostream>
#include <string>
#include <array>
#include <algorithm> // For search and binary search
#include <iomanip>

struct PersonInfo
{
   std::string personFirstName;
   std::string personLastName;
   std::string phoneNumber;
};

class AddressBook
{

public:
   static const int MAXSIZE = 3;

   void addName(std::string, std::string, std::string);
   static bool compareNames(PersonInfo, PersonInfo);
   void displayAllEntries();
   void displayAllFoundEntries();
   void sortData();
   void searchData(std::string, std::string);
   void resetFoundEntries();

   int getPositionIndex()
   {
      return positionIndex;
   }

   void increasePositionIndex()
   {
      positionIndex++;
   }

private:
   int positionIndex = 0;
   PersonInfo personInfo[MAXSIZE];
   PersonInfo foundPersonInfo[MAXSIZE];
   PersonInfo resetPersonInfo[MAXSIZE];
};

void AddressBook::addName(std::string fname, std::string lname, std::string phone)
{
   if (getPositionIndex() != MAXSIZE)
   {
      personInfo[getPositionIndex()].personFirstName = fname;
      personInfo[getPositionIndex()].personLastName = lname;
      personInfo[getPositionIndex()].phoneNumber = phone;
      increasePositionIndex();
   }
}

bool AddressBook::compareNames(PersonInfo person1, PersonInfo person2)
{
   if (person1.personLastName < person2.personLastName)
   {
      return true;
   }
   return false;
}

void AddressBook::displayAllEntries()
{
   std::cout << "All Entries" << std::endl;
   std::cout << std::left << std::setw(15) << "First Name"
             << std::left << std::setw(15) << "Last Name"
             << std::left << std::setw(15) << "Phone Number\n";

   for (size_t i = 0; i < positionIndex; i++)
   {
      std::cout << std::left << std::setw(15) << personInfo[i].personFirstName
                << std::left << std::setw(15) << personInfo[i].personLastName
                << std::left << std::setw(15) << personInfo[i].phoneNumber << "\n";
   }
}

void AddressBook::displayAllFoundEntries()
{
   std::cout << "Found Entries" << std::endl;
   std::cout << std::left << std::setw(15) << "First Name"
             << std::left << std::setw(15) << "Last Name"
             << std::left << std::setw(15) << "Phone Number\n";

   for (size_t i = 0; i < positionIndex; i++)
   {
      if (!foundPersonInfo[i].personLastName.empty())
      {
         std::cout << std::left << std::setw(15) << foundPersonInfo[i].personFirstName
                   << std::left << std::setw(15) << foundPersonInfo[i].personLastName
                   << std::left << std::setw(15) << foundPersonInfo[i].phoneNumber << "\n";
      }
   }
}

void AddressBook::sortData()
{
   std::sort(personInfo, personInfo + getPositionIndex(), compareNames);
}

void AddressBook::searchData(std::string fname, std::string lname)
{
   sortData();
   bool personFound = false;

   for (int i = 0; i < MAXSIZE; i++)
   {
      if (personInfo[i].personLastName == lname)
      {
         if (personInfo[i].personFirstName == fname)
         {
            // Add to found person struct
            foundPersonInfo[i].personFirstName = personInfo[i].personFirstName;
            foundPersonInfo[i].personLastName = personInfo[i].personLastName;
            foundPersonInfo[i].phoneNumber = personInfo[i].phoneNumber;
            personFound = true;
         }
      }
   }
   displayAllFoundEntries();
   if (personFound == false)
   {
      std::cout << "No matches in the Addressbook" << std::endl;
   }
   resetFoundEntries();
}

void AddressBook::resetFoundEntries()
{
   for (size_t i = 0; i < MAXSIZE; i++)
   {
      foundPersonInfo[i].personFirstName = resetPersonInfo[i].personFirstName;
      foundPersonInfo[i].personLastName = resetPersonInfo[i].personLastName;
      foundPersonInfo[i].phoneNumber = resetPersonInfo[i].phoneNumber;
   }
}
// Resources:
// https://www.geeksforgeeks.org/stdstringcompare-in-c/