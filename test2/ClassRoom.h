#include <iostream>
#include <array>
#include <algorithm>
#include <iomanip>

struct StudentInfo
{
    std::string firstName;
    std::string lastName;
    std::string studentID;
};

class ClassRoom
{
private:
    int numberStudents;
    std::string className;
    StudentInfo* roster = nullptr;

public:

    ClassRoom(int num = 5, std::string name = "CLAS-0101.X99")
    {
        numberStudents = num;
        className = name;
        roster = createRoster();
    }

    ~ClassRoom()
    {
        std::cout << "Destructor is Run" << std::endl;
        delete [] roster;
    }

    StudentInfo* createRoster()
    {
        return new StudentInfo[getNumberStudents()];
    }

    int getNumberStudents()
    {
        return numberStudents;
    }

    std::string getClassName()
    {
        return className;
    }

    void addName(std::string first, std::string last, std::string ID, int index)
    {
        (roster + index)->firstName = first;
        (roster + index)->lastName = last;
        (roster + index)->studentID = ID;
    }

    StudentInfo* getRoster()
    {
        return roster;
    }


    void findName(std::string id)
    {
        bool isFound = false;
        int i;

        for (i = 0; i < getNumberStudents(); i++)
        {
            if ((roster + i)->studentID == id)
            {
                isFound = true;
                break;
            }
            else
            {
                isFound = false;
            }
        }

        if (isFound == false)
        {
            std::cout << "Student Not Found" << std::endl;
        }
        else
        {
            std::cout << "Match Found\n"
                << "First Name: " << (roster + i)->firstName << std::endl
                << "Last Name: " << (roster + i)->lastName << std::endl;
        }
    }

    void printClassRosterInfo()
    {
        bubbleSort(roster, getNumberStudents());

        std::cout << "===== Class Roster for " << getClassName() << " =====\nNumber of students enrolled: " << getNumberStudents() << " \n\n" << 
            std::left << std::setw(15) << "Student ID" << std::setw(15) << "First Name" << std::setw(15) << "Last Name" << std::endl;

       // std::cout << std::setw(0);
        for (int i = 0; i < getNumberStudents(); i++)
        {
            std::cout << std::setw(15) << (roster + i)->studentID <<  std::setw(15) << (roster + i)->firstName << std::setw(15) << (roster + i)->lastName << std::endl;
        }
    }

    void bubbleSort(StudentInfo* array, int size)
    {
        //array = roster;
        for (int maxElement = size - 1; maxElement > 0; maxElement--)
        {
            for (int index = 0; index < maxElement; index++)
            {
                if (array[index].lastName > array[index + 1].lastName)
                {
                    swap(array[index], array[index + 1]);
                }
            }
        }
    }

    void swap(StudentInfo& a, StudentInfo& b)
    {
        StudentInfo temp = a;
        a = b;
        b = temp;
    }

    // Overloaded +
    ClassRoom operator+(ClassRoom& right)
    {
        int totalStudents = numberStudents + right.numberStudents;

        ClassRoom combinedRoster = ClassRoom(totalStudents, "Combined Classroom");

        // Populate first Roster into combined list
        for (int i = 0; i < numberStudents; i++)
        {
            *(combinedRoster.getRoster() + i) = *(roster + i);
        }

        // Populate second roster into combined list
        for (int j = numberStudents, k = 0; j < totalStudents; j++, k++)
        {
            *(combinedRoster.getRoster() + j) = *(right.roster + k);
        }
        return combinedRoster;
    }
};

