/* Filename: TwoDayPackage.h
   Title:  Header file TwoDayPackage.h
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, December 6, 2020
   Notes: Programming Challenge 8
*/
#include "Package.h"

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

class TwoDayPackage : public Package
{
private:
	double flatRateFee = 5.95;

public:
	TwoDayPackage(Address addressSender, Address addressRecipient, double weight, double costOunce, double flatRateFee);

	double calculateCost();
};

#endif
