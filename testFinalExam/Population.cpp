#include "Population.h"
using namespace std;

Population::Population()
{
	currentPopulation = 0;
	annualNumberOfBirths = 0;
	annualNumberOfDeaths = 0;
	birthRate = 0;
	deathRate = 0;
}

Population::Population(string currentPop, string annualNumBirths, string annualNumDeaths)
{
	currentPopulation = validatePopulation(currentPop);
	annualNumberOfBirths = validateNumBirthsDeaths(annualNumBirths, "Births");
	annualNumberOfDeaths = validateNumBirthsDeaths(annualNumDeaths, "Deaths");
	calculateBirthRate(currentPopulation, annualNumberOfBirths);
	calculateDeathRate(currentPopulation, annualNumberOfDeaths);
}

Population::Population(int currentPop, int annualNumBirths, int annualNumDeaths)
{
	setPopulation(currentPop);
	setBirths(annualNumBirths);
	setDeaths(annualNumDeaths);
	calculateBirthRate();
	calculateDeathRate();
}

unsigned int Population::validatePopulation(string population)
{
	int input;
	bool isValid = checkIfValid(population, &input);

	while (isValid == false)
	{
		//cout << "Your Input is not valid. Re-Enter: ";
		//cin.ignore();
		cout << "\nPopulation: ";
		cin >> population;
		isValid = checkIfValid(population, &input);
	}

	if (input <= 2 && input > 0)
	{
		cout << "Population less than or equal to 2. Defaults to 2.";
		return 2;
	}
	else if (input <= 0)
	{
		cout << "\nPopulation must be positive.\nPlease enter a valid entry: ";
		cin >> population;
		input = validatePopulation(population);
		return input;
	}
	else
		return input;
}

unsigned int Population::validateNumBirthsDeaths(string birthDeath, std::string statType)
{
	int input;
	bool isValid = checkIfValid(birthDeath, &input);

	while (isValid == false)
	{
		//cout << "Your Input is not valid. Re-Enter: ";
		//cin.ignore();
		cout << "\nNumber of " << statType << ": ";
		cin >> birthDeath;
		isValid = checkIfValid(birthDeath, &input);
	}

	if (input < 0)
	{
		cout << "\n\nNumber of " << statType << " is less than 0.\nPlease enter 0 or a postiive number: ";
		cin >> birthDeath;
		input = validateNumBirthsDeaths(birthDeath, "Birth");

		return input;
	}
	else
		return input;
}

void Population::setPopulation(string currentPop)
{
	currentPopulation = validatePopulation(currentPop);
}

void Population::setPopulation(int input)
{
	string population;

	if (input <= 2 && input > 0)
	{
		cout << "Population less than or equal to 2. Defaults to 2.";
		currentPopulation = 2;
	}
	else if (input <= 0)
	{
		cout << "Population must be positive.\nPlease enter a valid entry: ";
		cin >> population;
		validatePopulation(population);
		currentPopulation = input;
	}
	else
		currentPopulation = input;
}

void Population::setBirths(string annualNumberBirths)
{
	annualNumberOfBirths = validateNumBirthsDeaths(annualNumberBirths, "Births");
}

void Population::setBirths(int input)
{
	string birthDeath;
	string statType = "Birth";

	if (input < 0)
	{
		cout << "Number of << " << statType << " is less than 0.\nPlease enter 0 or a postiive number: ";
		cin >> birthDeath;
		validateNumBirthsDeaths(birthDeath, "Birth");

		annualNumberOfBirths = input;
	}
	else
		annualNumberOfBirths = input;
}

 void Population::setDeaths(string annualNumberDeaths)
{
	annualNumberOfDeaths = validateNumBirthsDeaths(annualNumberDeaths, "Deaths");
}

 void Population::setDeaths(int input)
{
	string birthDeath;
	string statType = "Death";

	if (input < 0)
	{
		cout << "Number of << " << statType << " is less than 0.\nPlease enter 0 or a postiive number: ";
		cin >> birthDeath;
		validateNumBirthsDeaths(birthDeath, "Birth");

		annualNumberOfDeaths = input;
	}
	else
		annualNumberOfDeaths = input;
}

void Population::reCalculateAll()
{
	calculateBirthRate();
	calculateDeathRate();
}

bool Population::checkIfValid(string input, int* value)
{
	bool isNegative = false;

	// check if input is valid, not a letter or punctuation
	int alpha = 0, number = 0, somethingElse = 0, i;
	for (i = 0; input[i] != '\0'; i++)
	{

		// check for alphabets
		if (isalpha(input[i]) != 0) {
			alpha++;
		}

		// check for decimal digits
		else if (isdigit(input[i]) != 0)
		{
			number++;
		}

		else if (isalpha(input[i]) == 0 && isdigit(input[i]) == 0)
		{
			if (i == 0 && input[0] == '-')
			{
				isNegative = true;
			}
			else
			{
				somethingElse++;
			}

		}
	}

	if (((isNegative == true) && (number == 0)) || (somethingElse != 0) || (alpha != 0))
	{
		cout << "\n\nInvalid Input. Please Re-Enter Value.";
		return false;
	}
	else
	{
		// All validated, store value in value via dereferenced pointer
		*(value) = stoi(input);
		return true;
	}
}



