#include "TwoDayPackage.h"

TwoDayPackage::TwoDayPackage(Address addressSender, Address addressRecipient, double weight, double costOunce, double flatRateFee) : Package(addressSender, addressRecipient, weight, costOunce)
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
