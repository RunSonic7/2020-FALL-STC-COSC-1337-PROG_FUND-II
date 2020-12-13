#include "OvernightPackage.h"

OvernightPackage::OvernightPackage(Address addressSender, Address addressRecipient, double weight, double costOunce) : Package(addressSender, addressRecipient, weight, costOunce)
{
}

double OvernightPackage::calculateCost()
{
	if (getWeightInOunces() > 0 && getCostPerOunce() > 0)
		return getWeightInOunces() * (getCostPerOunce() + overnightSurchargePerOunce);
	else
		return 0.0;
}


