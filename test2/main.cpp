#include <iostream>
#include <string>
#include "ClassRoom.h"
using namespace std;

int main()
{
	// Variables
	int sizeClassRoom1 = 5;
	string className1 = "COSC-1101.X31";

	// Create classroom object
	ClassRoom classroom1 = ClassRoom(sizeClassRoom1, className1);

	classroom1.addName("Juan", "Mireles", "A11111111", 0);
	classroom1.addName("Joe", "Alaniz", "A00005555", 1);
	classroom1.addName("Kevin", "Bose", "A12123232", 2);
	classroom1.addName("Carmen", "Torres", "A55550000", 3);
	classroom1.addName("Charlie", "Cortez", "A24682468", 4);

	// Display Class Roster
	classroom1.printClassRosterInfo();

	// SEARCH FOR MATCH 
	// Find a match
	string lookForID = "A55550000";
	cout << "\nMATCH SEARCH - Find\nLooking for student with ID " << lookForID << endl;
	classroom1.findName(lookForID);

	// Find not a match
	lookForID = "A12345678";
	cout << "\nMATCH SEARCH - No Match\nLooking for student with ID " << lookForID << endl;
	classroom1.findName(lookForID);

	// Create Second Class to test Overloaded operator
	ClassRoom classroom2 = ClassRoom();  // Defaults to 5 and default class name;

	classroom2.addName("Andrew", "Smith", "A66554433", 0);
	classroom2.addName("Joey", "Cruz", "A88552200", 1);
	classroom2.addName("Chase", "O'Brien", "A98798798", 2);
	classroom2.addName("Lenard", "Diaz", "A00000001", 3);
	classroom2.addName("Jimmy", "Williams", "A13571357", 4);

	cout << "\n\n";
	// Create 3rd classroom (combined) to test overloaded +
	ClassRoom combinedClassroom = classroom1 + classroom2;

	combinedClassroom.printClassRosterInfo();
}
