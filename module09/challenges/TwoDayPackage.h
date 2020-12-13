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
