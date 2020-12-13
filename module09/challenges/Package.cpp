/* Filename: Package.cpp
   Title:  Implementation file for Package.h
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, December 6, 2020
   Notes: Programming Challenge 8
*/
#include "Package.h"
using namespace std;

Package::Package(Address addressSender, Address addressRecipient, double weight, double costOunce)
{
	setAddressSender(addressSender);
	setAddressRecipient(addressRecipient);
	setWeight(weight);
	setCostPerOunce(costOunce);
}

void Package::setWeight(double weight)
{
	if (weight > 0.0)
		weightInOunces = weight;
	else
		cout << "Postive value required for weight. Unable to calculate cost";
}

inline double Package::getWeightInOunces()
{
	return weightInOunces;
}

inline void Package::setCostPerOunce(double cost)
{
	if (cost > 0.0)
		costPerOunce = cost;
	else
	{
		costPerOunce = 0.0;
		cout << "Postive value required for cost. Unable to calculate total cost";
	}
}

double Package::getCostPerOunce()
{
	return costPerOunce;
}

void Package::setAddressSender(Address address)
{
	sender = address;
}

void Package::setAddressRecipient(Address address)
{
	recipient = address;
}

Address Package::getAddressSender()
{
	return sender;
}

Address Package::getAddressRecipient()
{
	return recipient;
}

double Package::calculateCost()
{
	if (getWeightInOunces() > 0 && getCostPerOunce() > 0)
		return weightInOunces * costPerOunce;
	else
		return 0.0;
}
