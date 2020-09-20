/* Filename: car.h
   Title:  Car Accelerating/Braking
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, September 20, 2020
   Notes: Car Class via video provided modified
          This file definds a Car class and includes a client program
          that uses a Car object to simulate accelerating and breaking.
*/

#include <iostream>
#include "car.h"
using namespace std;

int main() {

    // Create Car Objects
    Car hotRod(2010, "Mazda");      

    // Describe the car (through this line was not erquired by the problem specs.)
    cout << "I'm in my " << hotRod.getYear() << " "
         << hotRod.getMake() << " hot rod.\n\n";

    // Accelerate
    cout << "I'm accelerating ... \n\n";
    for (int faster = 1; faster <= 5; faster++)
    {
        hotRod.accelerate();
        cout << "Current speed: " << hotRod.getSpeed() << "mph. \n";
    }

    // Now stop
    cout << "\nNow I'm breaking ... \n\n";
    for (int slower = 1; slower <= 5; slower++)
    {
        hotRod.brake();
        cout << "Current speed: " << hotRod.getSpeed() << " mph. \n";
    }

    cout << endl;
    return 0;
}