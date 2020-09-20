/* Filename: coin.h
   Title:  Coin Toss Simulator Implementation File
   
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
#include <string>
#include <cstdlib>
#include <ctime>

class Coin
{
private:
    std::string sideUp; // Private member

public:
    // Constructor and Member function prototypes
    Coin() {
        srand(time(0)); // Psuedo-random generator with seed
    toss();   
    };
    void toss();
    std::string getSideUp();
};

// Constructor, initialize sideUp member variable with heads/tails.
// By callling toss()
// Coin::Coin()
// {
//     srand(time(0)); // Psuedo-random generator with seed
//     toss();         // Initial Toss
// };

// Toss the coin to determine heads/tails.
void Coin::toss()
{
    // Modulus number so Either 0 = heads; 1 = tails
    int side = rand() % 2;

    if (side == 0)
    {
        sideUp = "Heads";
    }
    else
    {
        sideUp = "Tails";
    }
}

// Return the value of sideUp heads/tails.
std::string Coin::getSideUp()
{
    return sideUp;
}
