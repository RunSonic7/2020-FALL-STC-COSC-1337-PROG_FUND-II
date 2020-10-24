/* Filename: GradeBook.h
   Title: Implementation File for GradeBook Class

   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, October 18, 2020
   Notes: Implementation File for GradeBook Class
*/
#include <iostream>

class GradeBook
{
private:
    int* testScores;

    int size;
    std::string userInput;
    int userInputCast;

    bool isValidInput;
    bool isNumber;
    double average;

public:

    ~GradeBook()
    {
        delete[] testScores;
        testScores = 0;
    }

    void validateInput(std::string);
    bool checkIfNumber(std::string);
    void displayData();
    void calculateAverage();

    void modifyArray(int index, int grade)
    {  *(testScores + index) = grade;  }

    int getGradeBookSize()
    {  return size;  }

    void createGradebookArray()
    {  testScores = new int[size];  }

    void setSize()
    {  size = userInputCast;  }

    bool getIsValidInput()
    {  return isValidInput;  }

    void castToInt(std::string input)
    {  userInputCast = stoi(input);  }
};

void GradeBook::validateInput(std::string input)
{
    // Check if a positive number
    isNumber = checkIfNumber(input);

    if (isNumber == true)
    { // Number has already been casted
        if (userInputCast > 0) {
            isValidInput = true;

        }
        else
        {
            std::cout << "You did not input a valid entry. Please try again.\n" << std::endl;
            isValidInput = false;
        }
    }
    else
    {
        std::cout << "You did not input a valid entry. Please try again.\n" << std::endl;
        isValidInput = false;
    }
}

bool GradeBook::checkIfNumber(std::string input)
{
    // Check each character. Once false, loop breaks
    for (int i = 0; i < input.length(); i++)
    {
        if (isdigit(input[i]) == false)
        {
            return false;
        }
    }
    castToInt(input); // Since number, cast to int type
    return true;
};

void GradeBook::displayData()
{
    calculateAverage();
    for (int index = 0; index < size; index++)
    {
        std::cout << *(testScores + index) << std::endl;
    }
    std::cout << size << std::endl;
    std::cout << "The average is: " << average << std::endl;
}

void GradeBook::calculateAverage()
{
    for (int index = 0; index < size; index++)
    {
        double sum;
        sum += *(testScores + index);
        average = sum / size;
    }
}

// Sources:
// Destructor: https://docs.microsoft.com/en-us/cpp/cpp/destructors-cpp?view=vs-2019

