// This program shows how to pass an entire array to a function.
#include <iostream>
using namespace std;

void showValues(int intArray[], int size);  // Function prototype

void showValues2(int intArray[][int], int size);  // Function prototype

int main() {

    const int ARRAY_SIZE = 8;
    int collection[8] = {5, 10, 15, 20, 25, 30, 35, 40};
    int collection2[2][2] = {{2, 4}, {1, 3}};

    cout << "The array contains the values\n";

    showValues(collection, 8);
    return 0;
}

/* show Values
    This function displays the contents of an integer array
    when passed the array's address and its size as arguements.
*/
void showValues (int nums[], int size)
{
    for (int index = 0; index < size; index++)
        cout << nums[index] << "  ";
    cout << endl;
}

void showValues2 (int nums[][3], int size)
{
    for (int index = 0; index < size; index++)
        cout << nums[index] << "  ";
    cout << endl;
}