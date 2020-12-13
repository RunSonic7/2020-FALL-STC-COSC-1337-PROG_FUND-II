#include <iostream>

#ifndef ADDRESS_H
#define ADDRESS_H

class Address {
private:
	std::string name;
	std::string address;
	std::string city;
	std::string state;
	std::string zipCode;

public:
	Address();

	Address(std::string name, std::string address, std::string city, std::string state, std::string zipCode);

	std::string getName();

	std::string getAddress();

	std::string getCity();

	std::string getState();

	std::string getZipCode();
};

#endif 

