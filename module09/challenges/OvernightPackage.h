/* Filename: OvernightPackage.h
   Title:  Header file OvernightPackage.h
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, December 6, 2020
   Notes: Programming Challenge 8
*/
#include "Package.h"

#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

class OvernightPackage : public Package
{
private:
	const double overnightSurchargePerOunce = 4.95;
	// Question did not specify to have constructor initalize

public:
	OvernightPackage(Address addressSender, Address addressRecipient, double weight, double costOunce);

	double calculateCost();
};

#endif