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
#include <iomanip>

struct StudentInfo
{
    std::string studentName;
    int grade;
};

class GradeBook
{
private:

    int size;
    std::string userInput;
    int userInputCast;

    bool isValidInput;
    bool isNumber;
    double average;

public:

    void validateInputSize(std::string);
    void validateInputGrade(std::string);
    bool checkIfNumber(std::string);
    void displayData(StudentInfo*);
    void calculateAverage(StudentInfo*);
    void modifyArray(int, int, std::string, StudentInfo*);

    int getGradeBookSize()
    {  return size;  }

    // Return dynamic array created
    StudentInfo* createGradebookArray()
    {  return new StudentInfo[size];  }

    void setSize()
    {  size = userInputCast;  }

    bool getIsValidInput()
    {  return isValidInput;  }

    void castToInt(std::string input)
    {  userInputCast = std::stoi(input);  }
};

void GradeBook::validateInputSize(std::string input)
{
    // Check if a positive number
    isNumber = checkIfNumber(input);

    if (isNumber == true)
    { // Number has already been casted, cannot be 0
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

void GradeBook::validateInputGrade(std::string input)
{
    // Check if a positive number can be 0
    isNumber = checkIfNumber(input);

    if (isNumber == true)
    { // Number has already been casted
        if (userInputCast >= 0) 
        {
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

void GradeBook::displayData(StudentInfo* array)
{
    std::cout << "\n ----- Grade Report -----\n";

    calculateAverage(array);

    std::cout << std::setw(20) << std::left  << "Name" << std::setw(5) << std::right << "Grade" << std::endl;
    std::cout << "------------------- -----" << std::endl;
    
    // Show table of data
    for (int index = 0; index < size; index++)
    {
        std::cout << std::left << std::setw(20) << (array + index)->studentName << std::setw(5) << std::right << (array + index)->grade << std::endl;
    }
    //std::cout << size << std::endl;
    std::cout << "\nThe average is " << average << std::endl;
}

void GradeBook::calculateAverage(StudentInfo* array)
{
    for (int index = 0; index < size; index++)
    {
        double sum;
        sum += (array + index)->grade;
        average = sum / size;
    }
}

void GradeBook::modifyArray(int index, int grade, std::string name, StudentInfo* array)
{
    (array + index)->studentName = name;
    (array + index)->grade = grade;
}
