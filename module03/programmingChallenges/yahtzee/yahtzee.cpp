/* Filename: yahtzee.cpp
   Title:  Yahtzee Game Roll (1 reroll)
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, September 20, 2020
   Notes: Game Research, simulated one reroll (game rules allow 2 reroll).
          Credit to http://patorjk.com/software/taag/ for ASCII-Art Generator 
          of Yahtzee text.
*/

#include <iostream>
#include "die.h"
using namespace std;

/* Global Constants */
const int COUNT = 5;

// Function prototypes
void displayDiceValues(int[]);

int main()
{

    // Variables
    Die dice[COUNT];       // Array of Die objects
    char reRoll[COUNT];    // Determine to reroll or not reroll die
    int diceValues[COUNT]; // Value of die face
    char userChoice;       // User Input to reroll or not reroll die

    // Roll the dice ans store value
    for (int index = 0; index < COUNT; index++)
    {
        dice[index].roll();
        diceValues[index] = dice[index].returnSideUp();
    }

    // Display Title Intro and First Roll
    cout << "__  __            __     __                  \n"
         << "\\ \\/ /  ____ _   / /_   / /_ ____  ___   ___ \n"
         << " \\  /  / __ `/  / __ \\ / __//_  / / _ \\ / _ \\ \n"
         << " / /  / /_/ /  / / / // /_   / /_/  __//  __/\n"
         << "/_/   \\__,_/  /_/ /_/ \\__/  /___/\\___/ \\___/ \n";

    // Display first roll
    cout << "\n\nYour First Roll is: \n\n";
    displayDiceValues(diceValues);

    cout << "\n+--------------------------------------------+\n";
    cout << "| Time to decide what to keep (or not keep)! |\n";
    cout << "+--------------------------------------------+\n";

    for (int index = 0; index < COUNT; index++)
    {
        cout << "\nWould you like to re-roll dice " << index + 1 << "?\nEnter Y or y to reroll, or anything else to keep: ";
        cin >> userChoice;

        if ((userChoice == 'Y') || (userChoice == 'y'))
        {
            reRoll[index] = 'Y';
        }
        else
        {
            reRoll[index] = 'N';
        }
    }
    cout << endl;

    // Reroll chosen die

    for (int index = 0; index < COUNT; index++)
    {
        if (reRoll[index] == 'Y')
        {
            dice[index].roll();
            diceValues[index] = dice[index].returnSideUp();
        }
    }

    // Redisplay values
    cout << "\nYour Roll is: \n\n";
    displayDiceValues(diceValues);

    return 0;
}

// Functions
void displayDiceValues(int values[])
{
    for (int index = 0; index < COUNT; index++)
    {
        cout << "Dice " << index + 1 << ":   " << values[index] << endl;
    }
}