#include <iostream>
#include <array> // Required for use of arrays
#include "Validation.h"
#include <string>
using namespace std;

int main()
{

    Validation k;
    const int MAXSIZE = 20;
    int counter = 0;
    string userInput;
    array<int, MAXSIZE> n = {0};
    bool isDuplicate;
    int arrayIncrementer = 0;

    while (counter < MAXSIZE)
    {
        while (k.getIsValidInput() == false)
        {
            cout << "Please input a number: ";
            cin >> userInput;
            k.validateInput(userInput);
        }

        // Check if duplicate in array
        for (int i = 0; i < counter + 1; i++)
        {
            if (k.getUserInput() == n[i])
            {
                // Duplicate do not add to array, end loop
                isDuplicate = true;
                break;
            }
            isDuplicate = false;
        }

        if (isDuplicate == false)
        {
            n[counter] = k.getUserInput();
        }

        counter++;
        cout << counter << endl;
        k.setIsValidInput(false); // Reset valid input.
    }

    // Print Array to User
    for (int i = 0; i < MAXSIZE; i++)
    {
        if(n[i] != 0)
            cout << n[i] << " ";
    }

    return 0;
}