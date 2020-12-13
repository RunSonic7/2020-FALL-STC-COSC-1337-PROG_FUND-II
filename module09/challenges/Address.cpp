/* Filename: Address.cpp
   Title:  Implementation file for Address.h
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, December 6, 2020
   Notes: Programming Challenge 8
*/
#include "Address.h"

Address::Address() {

	name = "";
	address = "";
	city = "";
	state = "";
	zipCode = "00000";

};

Address::Address(std::string name, std::string address, std::string city, std::string state, std::string zipCode)
{
	this->name = name;
	this->address = address;
	this->city = city;
	this->state = state;
	this->zipCode = zipCode;
}

std::string Address::getName()
{
	return name;
}

std::string Address::getAddress()
{
	return address;
}

std::string Address::getCity()
{
	return city;
}

std::string Address::getState()
{
	return state;
}

std::string Address::getZipCode()
{
	return zipCode;
}