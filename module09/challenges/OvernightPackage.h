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