/* Filename: Package.h
   Title:  Header file Package.h
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, December 6, 2020
   Notes: Programming Challenge 8
*/
#include <iostream>
#include "Address.h"

#ifndef PACKAGE_H
#define PACKAGE_H

class Package
{
private:
	Address sender;
	Address recipient;
	double weightInOunces;
	double costPerOunce;

public:
	Package(Address addressSender, Address addressRecipient, double weight, double costOunce);

	void setWeight(double weight);

	double getWeightInOunces();

	void setCostPerOunce(double cost);

	double getCostPerOunce();

	void setAddressSender(Address address);

	void setAddressRecipient(Address address);

	Address getAddressSender();

	Address getAddressRecipient();

	double calculateCost();
};

#endif
