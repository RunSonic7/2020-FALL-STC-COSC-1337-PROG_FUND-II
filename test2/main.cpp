#include <iostream>
#include <string>
#include "ClassRoom.h"
using namespace std;

void displayTitle();
bool checkIfNumber(string input);
int castToInt(string input);

int main()
{
	// Variables
	ClassRoom classRoom;
	string numStudentsInput;
	int numStudents = 0;
	string numStudentsToAddInput;
	int numStudentsToAdd = 0;
	string className;
	bool isNumber = false;
	string studentID;

	//string firstName;
	//string lastName;
	//string studentID;
	StudentInfo studentInfoInput;
	
	// Start of Program
	displayTitle();

	// Ask to enter number of students
	cout << "Enter the number of students: ";
	cin >> numStudentsInput;

	do
	{	// Loop until valid
		isNumber = checkIfNumber(numStudentsInput);

		if (isNumber == true)
		{	// cast string input to int
			numStudents = castToInt(numStudentsInput);
		}
		else
		{	// Prompt reentry of value
			cout << "Invalid Input.\n";
			cout << "Enter the number of students: ";
			cin >> numStudentsInput;
		}
	} while (isNumber == false);

	// Enter name of class
	cout << "Enter class name: ";
	cin.ignore();
	getline(cin, className);

	// Create classroom object
	ClassRoom classroom = ClassRoom(numStudents, className);

	// Add number of students to class
	for (int i = 0; i < numStudents; i++)
	{
		cout << "First Name: ";
		getline(cin, studentInfoInput.firstName);

		cout << "Last Name: ";
		getline(cin, studentInfoInput.lastName);

		cout << "Student ID: ";
		getline(cin, studentInfoInput.studentID);

		classroom.addName(studentInfoInput, i);
	}
	classroom.printClassRosterInfo();
	// Find a particular student
	cout << "Find Student\nEnter Student ID: ";
	getline(cin, studentID);

	classroom.findName(studentID);
	
	classroom.printClassRosterInfo();







	// Test code
	cout << classroom.getNumberStudents() << endl;
	cout << classroom.getClassName() << endl;
	// End Test code


	//classroom.~ClassRoom();  FIX THIS!!!
}

void displayTitle()
{
	cout << "=== Class Roster System ===\n\n";
}

bool checkIfNumber(string input)
{
	// Check each character. Once false, loop breaks
	for (unsigned int i = 0; i < input.length(); i++)
	{
		if (isdigit(input[i]) == false)
		{
			return false;
		}
	}
	//castToInt(input); // Since number, cast to int type
	return true;
};

int castToInt(string input)
{
	return stoi(input);
}