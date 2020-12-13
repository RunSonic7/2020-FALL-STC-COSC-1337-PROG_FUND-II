/* Filename: OvernightPackage.cpp
   Title:  Implementation file for OvernightPackage.h
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, December 6, 2020
   Notes: Programming Challenge 8
*/
#include "OvernightPackage.h"
using namespace std;

OvernightPackage::OvernightPackage(Address addressSender, Address addressRecipient, 
double weight, double costOunce) : Package(addressSender, addressRecipient, weight, costOunce)
{
}

double OvernightPackage::calculateCost()
{
	if (getWeightInOunces() > 0 && getCostPerOunce() > 0)
		return getWeightInOunces() * (getCostPerOunce() + overnightSurchargePerOunce);
	else
		return 0.0;
}


