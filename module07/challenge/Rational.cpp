/* Filename: Rational.cpp
   Title:  Implementation file for Rational Class Challenge (Overloaded Operators)

   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, November 15, 2020
   Notes:
*/

#include <iostream>
#include "Rational.h"
using namespace std;

Rational::Rational()
{
	numerator = 1;
	denominator = 1;
	isValidtoCalculate = true;
}

Rational::Rational(int numerator, int denominator) : Rational()
{
	this->numerator = numerator;
	this->denominator = denominator;
	doubleNegativeCheck();
}

Rational::Rational(int numerator, int denominator, bool isValidtoCalculate) : Rational()
{
	this->numerator = numerator;
	this->denominator = denominator;
	this->isValidtoCalculate = isValidtoCalculate;
}

Rational::Rational(string numerator, string denominator)
{
	if (validateInput(numerator) == true)
	{
		this->numerator = stringToInt(numerator);
	}
	else
	{
		cout << "Invalid Numerator Input - Defaulted to 1" << endl;
		this->numerator = 1;
	}

	if (validateInput(denominator) == true)
	{
		if (denominator == "0")
		{
			cout << "Cannot have 0 denominator - Defaulted to 1" << endl;
			this->denominator = 1;
		}
		else
		{
			this->denominator = stringToInt(denominator);
		}
	}
	else
	{
		cout << "Invalid Denominator Input - Defaulted to 1" << endl;
		this->denominator = 1;
	}

	reduceForm(this->numerator, this->denominator);

	// Check if both negative
	doubleNegativeCheck();
}

void Rational::reduceForm(int& x, int& y)
{
	int gcf;

	gcf = abs(greatCommFactor(x, y)); // Prevent sign change

	x = x / gcf;
	y = y / gcf;
}

void Rational::reduceForm(Rational& fraction)
{
	int gcf;
	gcf = abs(greatCommFactor(fraction.getNumerator(), fraction.getDenominator()));

	fraction.setNumerator(fraction.getNumerator() / gcf);
	fraction.setDenominator(fraction.getDenominator() / gcf);
}

bool Rational::getIsValidToCalculate()
{
	return isValidtoCalculate;
}

int Rational::getNumerator()
{
	return numerator;
}

int Rational::getDenominator()
{
	return denominator;
}

void Rational::setNumerator(int numerator)
{
	this->numerator = numerator;
}

void Rational::setDenominator(int denominator)
{
	this->denominator = denominator;
}

int Rational::stringToInt(string s)
{
	return stoi(s);
}

int Rational::greatCommFactor(int a, int b)
{

	if (b == 0)
		return a;
	return greatCommFactor(b, a % b);
}

bool Rational::validateInput(string input)
{
	bool isNegative = false;

	int alpha = 0, number = 0, somethingElse = 0, i;
	for (i = 0; input[i] != '\0'; i++)
	{

		// check for alphabets
		if (isalpha(input[i]) != 0) {
			alpha++;
		}


		// check for decimal digits
		else if (isdigit(input[i]) != 0)
		{
			number++;
		}


		else if (isalpha(input[i]) == 0 && isdigit(input[i]) == 0)
		{
			if (i == 0 && input[0] == '-')
			{
				isNegative = true;
			}
			else
			{
				somethingElse++;
			}

		}
	}

	if (((isNegative == true) && (number == 0)) || (somethingElse != 0) || (alpha != 0))
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Rational::doubleNegativeCheck(Rational& f)
{
	if (f.getNumerator() < 0 && f.getDenominator() < 0)
	{
		f.setNumerator(-1 * f.getNumerator());
		f.setDenominator(-1 * f.getDenominator());
	}
}

void Rational::doubleNegativeCheck()
{
	if (numerator < 0 && denominator < 0)
	{
		numerator *= -1;
		denominator *= -1;
	}
}

Rational Rational::add(Rational frac)
{
	Rational sum;

	sum.setNumerator(numerator * frac.getDenominator() + denominator * frac.getNumerator());

	sum.setDenominator(denominator * frac.getDenominator());

	reduceForm(sum);

	return sum;
}

Rational Rational::subtract(Rational frac)
{
	Rational difference;

	difference.setNumerator(numerator * frac.getDenominator()
		- denominator * frac.getNumerator());

	difference.setDenominator(denominator * frac.getDenominator());

	reduceForm(difference);

	return difference;
}

Rational Rational::multiply(Rational frac)
{
	Rational product;

	product.setNumerator(numerator * frac.getNumerator());
	product.setDenominator(denominator * frac.getDenominator());

	reduceForm(product);
	return product;
}

Rational Rational::divide(Rational frac)
{
	Rational quotient;

	// Check to ensure second fraction does not have numerator
	// of 0 as cannot divide by 0.
	if (frac.getNumerator() == 0)
	{
		isValidtoCalculate = false;
		return Rational(1, 1, isValidtoCalculate);
	}

	// continue computing
	quotient.setNumerator(numerator * frac.getDenominator());
	quotient.setDenominator(denominator * frac.getNumerator());

	reduceForm(quotient);
	return quotient;
}

Rational Rational::operator+(Rational &right)
{
	int totalNumerator = numerator * right.denominator + denominator * right.numerator;
	int totalDenominator = denominator * right.denominator;

	Rational sum(totalNumerator, totalDenominator);
	reduceForm(sum);
	return sum;
}

Rational Rational::operator-(Rational &right)
{
	int totalNumerator = numerator * right.denominator - denominator * right.numerator;
	int totalDenominator = denominator * right.denominator;

	Rational difference(totalNumerator, totalDenominator);
	reduceForm(difference);
	return difference;
}

Rational Rational::operator*(Rational &right)
{
	int totalNumerator = numerator * right.numerator;
	int totalDenominator = denominator * right.denominator;

	Rational product(totalNumerator, totalDenominator);
	reduceForm(product);
	return product;
}

Rational Rational::operator/(Rational &right)
{
	// Check to ensure second fraction does not have numerator
	// of 0 as cannot divide by 0.
	if (right.numerator == 0)
	{
		isValidtoCalculate = false;
		return Rational(1, 1, isValidtoCalculate);
	}

	// continue computing
	int totalNumerator = numerator * right.denominator;
	int totalDenominator = denominator * right.numerator;

	Rational quotient(totalNumerator, totalDenominator);
	reduceForm(quotient);
	return quotient;
}

double Rational::decimalForm()
{
	return (double)getNumerator() / getDenominator();
}