/* Filename: Rational.h
   Title:  Interface file for Rational Class Challenge

   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, November 1, 2020
   Notes:
*/

#include <iostream>
#include <string> // for stoi()

#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
private:
	int numerator;
	int denominator;
	bool isValidtoCalculate;

public:
	
	// Default initializers
	Rational();

	// If inputs are ints (like for solution)
	Rational(int numerator, int denominator);

	// If inputs are ints (like for solution)  for division
	Rational(int numerator, int denominator, bool isValidtoCalculate);

	// If inputs are strings, i.e. user input
	Rational(std::string numerator, std::string denominator);

	// Grab by reference as we want to store as reduced value
	void reduceForm(int& x, int& y);

	void reduceForm(Rational& fraction);

	bool getIsValidToCalculate();

	int getNumerator();

	int getDenominator();

	void setNumerator(int numerator);

	void setDenominator(int denominator);

	int stringToInt(std::string s);

	// Recursive function to return gcd of a and b
	//https://www.geeksforgeeks.org/c-program-find-gcd-hcf-two-numbers/
	int greatCommFactor(int a, int b);

	// Validate user input on String Input
	bool validateInput(std::string input);

	void doubleNegativeCheck(Rational& f);

	void doubleNegativeCheck();

	Rational add(Rational frac);

	Rational subtract(Rational frac);

	Rational multiply(Rational frac);

	Rational divide(Rational frac);

	double decimalForm();
};

#endif
