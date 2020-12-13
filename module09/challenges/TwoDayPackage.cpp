/* Filename: TwoDayPackage.cpp
   Title:  Implementation file for TwoDayPackage.h
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, December 6, 2020
   Notes: Programming Challenge 8
*/
#include "TwoDayPackage.h"
using namespace std;

TwoDayPackage::TwoDayPackage(Address addressSender, Address addressRecipient, 
double weight, double costOunce, double flatRateFee) : Package(addressSender, 
addressRecipient, weight, costOunce)
{
	this->flatRateFee = flatRateFee;
}

double TwoDayPackage::calculateCost()
{
	if (getWeightInOunces() > 0 && getCostPerOunce() > 0)
		return getWeightInOunces() * getCostPerOunce() + flatRateFee;
	else
		return 0.0;
}
