#include <iostream>
#include <array>
#include <typeinfo>
#include <sstream>

class Validation
{
private:
    std::string userInput;
    bool isValidInput = false;
    bool isNumber = false;
    bool isInRange = false;
    int userInputCast;

public:
    void validateInput(std::string input)
    {

        setUserInput(input);                 // Set member variable to input of user
        isNumber = checkIfNumber(userInput); // Check if what user input is a number or not

        if (isNumber)
        {
            isInRange = checkRange(userInputCast);

            if (isInRange)
            {
                setIsValidInput(true);
            }
            else
            {
                std::cout << "Your input is out of range.\nPlease enter a value between 1 and 20.\n\n";
                setIsValidInput(false);
            }
        }
        else
        {
            std::cout << "Your input is invalid. Please re-enter a valid entry.\n";
            setIsValidInput(false);
        }
    }

    void setIsValidInput(bool tf)
    {
        isValidInput = tf;
    }

    bool getIsValidInput() {
        return isValidInput;
    }

    void setUserInput(std::string input)
    {
        userInput = input;
    }

    int getUserInput()
    {
        return userInputCast;
    }

    bool checkIfNumber(std::string input)
    {
        // Check each character. Once false, loop breaks
        for (int i = 0; i < input.length(); i++)
        {
            if (isdigit(input[i]) == false)
            {
                std::cout << "Not a integer" << std::endl;
                ; // ---- DELETE WHEN DONE
                return false;
            }
        }
        // If all characters are integers. Cast to Integer
        std::cout << "Integer" << std::endl; // --- DELETE WHEN DONE
        castToInt(input);                    // Since number, cast to int type
        return true;
    };

    void castToInt(std::string input)
    {
        userInputCast = stoi(input);
    }

    bool checkRange(int num)
    {
        if (num >= 1 && num <= 20)
            return true;
        else
            return false;
    }

    // void getUserInput(std::string);
};

// void Eliminiation::getUserInput(std::string input)
// {
//     // userInput = input;
//     // isValidInput = checkIsNumber(userInput);
//     //isInputInRange = checkRange();

//     // if (isValidInput == false)
//     // {
//     //     std::cout << "Your Input is not valid, please try again." << std::endl;
//     // }
//     // else
//     // {
//     //     castToInt(userInput);

//     //     if (checkRange(userInputCast) == false)
//     //     {
//     //         std::cout << "Your input is out of range, please remember to choose number between 1 and 20." << std::endl;

//     //     }
//     //     else
//     //     {
//     //         std::cout << "In Range" << std::endl;
//     //     }

//     //     // Continue here
//     // }
// }

// Source for isNumber Code
// https://www.geeksforgeeks.org/program-check-input-integer-string/
// Resources
// https://www.geeksforgeeks.org/converting-strings-numbers-cc/