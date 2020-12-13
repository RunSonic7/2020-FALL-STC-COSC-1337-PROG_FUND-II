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
