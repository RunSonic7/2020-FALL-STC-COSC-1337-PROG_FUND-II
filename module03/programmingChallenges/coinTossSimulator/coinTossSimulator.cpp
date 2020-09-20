/* Filename: coinTossSimulator.cpp
   Title:  Coin Toss Simulator
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, September 20, 2020
   Notes: Credit to http://patorjk.com/software/taag/ for ASCII-Art Generator 
          of Yahtzee text.
*/

#include <iostream>
#include "coin.h"
using namespace std;

// Global Constants & Variables
const int COIN_TOSSES = 20;
int counterHeads = 0;
int counterTails = 0;

void increment(string); // Function prototypes

int main()
{
   // Variables
   Coin quarter;
   string initialFlipSide;

   // Title ASCII Art
   cout << "         _____ ____   ____ _  __  ______ ____   ____ ____     \n";
   cout << "  _//   / ___// __ \\ /  _// |/ / /_  __// __ \\ / __// __/ __//\n";
   cout << " (_-<  / /__ / /_/ /_/ / /    /   / /  / /_/ /_\\ \\ _\\ \\  / __/\n";
   cout << "/ __/  \\___/ \\____//___//_/|_/   /_/   \\____//___//___/  \\ _/ \n";
   cout << "//                                                       //  \n\n";

   // Initial flip
   cout << "It's " << quarter.getSideUp() << "\n\n";
   initialFlipSide = quarter.getSideUp();

   for (int index = 0; index < COIN_TOSSES; index++)
   {
      quarter.toss();
      cout << "Toss " << index + 1 << " is " << quarter.getSideUp() << endl;

      increment(quarter.getSideUp());
   }

   // Display Totals to user

   cout << "\nCoin Flip Results (Not Including Initial Flip)\n"
        << "Total Heads: " << counterHeads << endl
        << "Total Tails: " << counterTails << endl;

   // Consider Initial Flip
   increment(initialFlipSide);

   cout << "\nCoin Flip Results (Including Initial Flip)\n"
        << "Total Heads: " << counterHeads << endl
        << "Total Tails: " << counterTails << endl;

   return 0;
}

void increment(string coinSide)
{
   if (coinSide == "Heads")
   {
      counterHeads++;
   }
   else
   {
      counterTails++;
   }
}