/* Filename: main.cpp
   Title:  Driver file for Rational Class Challenge (Overloaded Operators)

   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, November 15, 2020
   Notes: 9.6 (Rational Class) Create a class called Rational (separate the
		  files as shown in the chapter) for performing arithmetic with
		  fractions. Write a program to test your class. Use integer variables
		  to represent the private data of the class-the numerator and the
		  denominator. Provide a constructor that enables an object of this
		  class to be initialized when it's declared. The constructor should
		  contain default values in case no initializers are provided and should
		  store the fraction in reduced form. For example, the fraction 2/4
		  would be stored in the object as 1 in the numerator and 2 in the
		  denominator. Provide public member functions that perform each of the
		  following tasks:

		  Make an overloaded operator of the + symbol for the add method -
		  Adds two Rational numbers. The result should be stored in reduced form.

		  Make an overloaded operator of the - symbol for the subtract method -
		  Subtracts two Rational numbers. Store the result in reduced form.

		  Make an overloaded operator of the * symbol for the multiply method -
		  Multiples two Rational numbers. Store the result in reduced form.

		  Make an overloaded operator of the / symbol for the divide method  -
		  Divides two Rational numbers. The result should be stored in reduced form.

		  NO CHANGES TO THIS (toRationalString - optional uses iostream from
		  previous chapter - extra credit) - Returns a string representation of
		  a Rational number in the form a/b, where a is the numerator and b is
		  the denominator.
		  NO CHANGES TO THIS  | display - Display the Rational number a/b.
		  NO CHANGES TO THIS  | toDouble - Returns the Rational number as a double.
		  (make sure the driver tests out all the overloaded operators)
*/

#include <iostream>
#include "Rational.h"
using namespace std;

void displayRational(Rational);

int main()
{
	string userInputNumerator;
	string userInputDenominator;
	Rational fraction1 = Rational();
	Rational fraction2 = Rational();
	Rational solution = Rational();

	// Prompt user to enter first rational number
	cout << "Enter the first rational number: " << endl;
	cout << "Numerator: ";
	cin >> userInputNumerator;

	cout << "Denominator: ";
	cin >> userInputDenominator;

	// Store in object
	fraction1 = Rational(userInputNumerator, userInputDenominator);
	cout << "Your input has been reduced to " << fraction1.getNumerator() << " / " << fraction1.getDenominator() << endl;
	displayRational(fraction1);

	// Prompt user to enter second rational number
	cout << "\nEnter a second rational number: " << endl;
	cout << "Numerator: ";
	cin >> userInputNumerator;

	cout << "Denominator: ";
	cin >> userInputDenominator;

	// store in object
	fraction2 = Rational(userInputNumerator, userInputDenominator);
	cout << "Your input has been reduced to ";
	displayRational(fraction2);

	// Display Current Inputs
	cout << "\nCurrent Data\n";
	cout << "Fraction 1 is ";
	displayRational(fraction1);
	cout << "Fraction 2 is ";
	displayRational(fraction2);

	// Perform operations
	// Multiply
	solution = fraction1.multiply(fraction2);
	cout << "\nMultiply: ";
	displayRational(solution);

	// Divide
	solution = fraction1.divide(fraction2);
	if (solution.getIsValidToCalculate() == false)
	{
		cout << "Divide: Unable to calculate divide by 0\n";
	}
	else
	{
		cout << "Divide: ";
		displayRational(solution);
	}

	// Add
	solution = fraction1.add(fraction2);
	cout << "Add: ";
	displayRational(solution);

	// Subtract
	solution = fraction1.subtract(fraction2);
	cout << "Subtract: ";
	displayRational(solution);

	// To Double
	cout << "\nFraction 1 Decimal Form: " << fraction1.decimalForm() << endl;
	cout << "Fraction 2 Decimal Form: " << fraction2.decimalForm() << endl;

	// Overloaded operators
	cout << "\n\n Overloaded Operations \n" << endl;
	// Perform operations
	// Multiply
	solution = fraction1 * fraction2;
	cout << "\nMultiply: ";
	displayRational(solution);

	// Divide
	solution = fraction1 / fraction2;
	if (solution.getIsValidToCalculate() == false)
	{
		cout << "Divide: Unable to calculate divide by 0\n";
	}
	else
	{
		cout << "Divide: ";
		displayRational(solution);
	}

	// Add
	solution = fraction1 + fraction2;
	cout << "Add: ";
	displayRational(solution);

	// Subtract
	solution = fraction1 - fraction2;
	cout << "Subtract: ";
	displayRational(solution);




	return 0;
}

void displayRational(Rational r)
{
	cout << r.getNumerator() << " / " << r.getDenominator() << endl;
}
