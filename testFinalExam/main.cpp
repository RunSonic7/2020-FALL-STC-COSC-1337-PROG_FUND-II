#include <iostream>
#include <string>	// For stoi
#include <iomanip>
#include "Population.h"
using namespace std;

// Prototypes
void displayTitle();
void displayStatistics(Population&, string);

int main()
{
	// Variables
	string userInputPopulation;
	string userInputBirths;
	string userInputDeaths;

	bool isValidInput = false;


	// start of program
	displayTitle();

	// By User input into constructor
	cout << "Enter total Population: ";
	cin >> userInputPopulation;

	cout << "Enter annual number of Births: ";
	cin >> userInputBirths;

	cout << "Enter annual number of Deaths ";
	cin >> userInputDeaths;

	Population population = Population(userInputPopulation, userInputBirths, userInputDeaths);

	displayStatistics(population, "Via User Input");

	// With setter functions
	Population population2;
	population2.setPopulation("100000");
	population2.setBirths("8000");
	population2.setDeaths("6000");
	population2.reCalculateAll();

	displayStatistics(population2, "Via setter member functions/Default constructor");

	// Overloaded Constructor ints
	Population population3 = Population(100000, 8000, 6000);
	displayStatistics(population3, "Via Overloaded Constructor with ints");

	// Overloaded int inputs
	Population population4;
	population4.setPopulation(100000);
	population4.setBirths(8000);
	population4.setDeaths(6000);
	population4.calculateBirthRate();
	population4.calculateDeathRate();
	
	displayStatistics(population4, "Via Default Constructor with overloaded setter functions");


	return 0;
}

void displayTitle()
{
	cout << "+---------------------------------+\n"
		<< "|   BIRTH/DEATH RATE CALCULATOR   |\n"
		<< "+---------------------------------+\n\n";
}

void displayStatistics(Population& statistics, string title)
{
	// Pass by reference, no need to copy data again
	cout << "\n\nPopulation Statistics - " << title << "\n\n";

	
	cout << "\tPopulation:\t" << statistics.getPopulation() << endl;
	cout << fixed << setprecision(3);
	// round will truncate everything, need to make an int then divide
	cout << "\tBirth Rate:\t" << (round(statistics.getBirthRate() * 1000)) / 1000 << endl;
	cout << "\tDeath Rate:\t" << (round(statistics.getDeathRate() * 1000)) / 1000 << endl;
}





