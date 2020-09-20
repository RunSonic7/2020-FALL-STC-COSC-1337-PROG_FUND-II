/* Filename: car.h
   Title:  Car Implementation File
   
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
#include <string>

class Car
{
    private:
        int year;         // Model year of the Car
        std::string make; // Make of the Car
        int speed;        // Current speed of the Car (mph)

    public:
        // Constructor with default parameters and Member function prototypes
        Car(int y = 2010, std::string m = "Unknown")
        {
            year = y;
            make = m;
            speed = 0;
        }
        void brake();

        // Accessors (i.e. "get" functions)
        int getYear()
        {   return year;   }

        std::string getMake()
        {   return make;   }

        int getSpeed()
        {   return speed;   }

        // Mutators (i.e. "set" functions)
        void accelerate()
        {   speed += 5;   }
};

// not "short", therefore inline is discouraged
void Car::brake()
{
    if (speed >= 5)
    {
        speed -= 5;
    }
    else
    {
        speed = 0;
    }
}