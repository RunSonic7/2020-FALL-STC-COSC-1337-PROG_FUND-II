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