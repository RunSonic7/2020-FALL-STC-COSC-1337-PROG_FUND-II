#include <iostream>
#include <string>

#ifndef POPULATION_H
#define POPULATION_H

class Population {
private:
	unsigned int currentPopulation,
		annualNumberOfBirths,
		annualNumberOfDeaths;
	double birthRate,
		deathRate;

public:
	Population();

	Population(std::string currentPop, std::string annualNumBirths, std::string annualNumDeaths);

	Population(int currentPop, int annualNumBirths, int annualNumDeaths);

	unsigned int validatePopulation(std::string population);

	unsigned int validateNumBirthsDeaths(std::string birthDeath, std::string statType);

	void setPopulation(std::string currentPop);

	void setPopulation(int input);

	void setBirths(std::string annualNumberBirths);

	void setBirths(int input);

	void setDeaths(std::string annualNumberDeaths);

	void setDeaths(int input);

	unsigned int getPopulation() const
	{
		return currentPopulation;
	}

	unsigned int getBirths() const
	{
		return annualNumberOfBirths;
	}

	unsigned int getDeaths() const
	{
		return annualNumberOfDeaths;
	}

	void calculateBirthRate()
	{
		birthRate = getBirths() / (double)getPopulation();
	}

	void calculateBirthRate(unsigned int population, unsigned int numBirths)
	{
		birthRate = numBirths / (double)population;
	}

	void calculateDeathRate() 
	{
		deathRate = getDeaths() / (double)getPopulation();
	}

	void calculateDeathRate(unsigned int population, unsigned int numDeaths)
	{  deathRate = numDeaths / (double)population;	}

	void reCalculateAll();

	double getBirthRate() const
	{
		return birthRate;
	}

	double getDeathRate() const
	{  return deathRate;	}

	bool checkIfValid(std::string input, int* value);
};





#endif

