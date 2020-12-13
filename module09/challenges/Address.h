/* Filename: Address.h
   Title:  Header file Address.h
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, December 6, 2020
   Notes: Programming Challenge 8
*/
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

