#include <iostream>

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

    int* testScores;

    ~GradeBook()
    {
        delete[] testScores;
        testScores = 0;
    }

    void validateInput(std::string input)
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

    int getGradeBookSize()
    {
        return size;
    }

    void createGradebookArray()
    {
        testScores = new int[size];
    }

    void setSize()
    {
        size = userInputCast;
    }
    
    bool getIsValidInput()
    {
        return isValidInput;
    }

    bool checkIfNumber(std::string input)
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

    void displayData()
    {
        calculateAverage();
        for (int index = 0; index < size; index++)
        {
            std::cout << *(testScores + index) << std::endl;
        }
        std::cout << size << std::endl;
        std::cout << "The average is: " << average << std::endl;
    }

    void calculateAverage()
    {
        for (int index = 0; index < size; index++)
        {
            double sum;
            sum += *(testScores + index);
            average = sum / size;
        }

    }
    void castToInt(std::string input)
    {
        userInputCast = stoi(input);
    }
};

// GradeBook::GradeBook(/* args */)
// {
// }


// Sources:
// Destructor: https://docs.microsoft.com/en-us/cpp/cpp/destructors-cpp?view=vs-2019

