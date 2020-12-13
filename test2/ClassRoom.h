#include <iostream>
#include <array>
#include <algorithm>

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

    ClassRoom(int num = 10, std::string name = "CLAS-0101.X99")
    {
        numberStudents = num;
        className = name;
        roster = createRoster();
    }

    ~ClassRoom() // FIX THIS!
    {
        //delete roster;
        //roster = 0;
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

    // Methods to add
    void addName(StudentInfo info, int index)
    {
        (roster + index)->firstName = info.firstName;
        (roster + index)->lastName = info.lastName;
        (roster + index)->studentID = info.studentID;
    }

    // Methods to add
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

    // void printClassRosterInfo()
    // {
    //     for (int i = 0; i < getNumberStudents(); i++)
    //     {
    //         std::cout << (roster + i)->firstName << " " << (roster + i)->lastName << " " << (roster + i)->studentID << std::endl;
    //     }
    // }

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

        for (int i = 0; i < getNumberStudents(); i++)
         {
             std::cout << (roster + i)->firstName << " " << (roster + i)->lastName << " " << (roster + i)->studentID << std::endl;
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

    void swap(StudentInfo &a, StudentInfo &b)
    {
        StudentInfo temp = a;
        a = b;
        b = temp;
    }


    // display name of class, number of students and student names sorted by last name.
    //
    //overloaded+ plus combine number of students with the list of students.
    // i.e. one class has 10 students, the other has 15, when added together, shoudl have 35 students in the class (dynamic arrays).
    //StudentInfo studentInfo[students];
    // private:
    //    std::array<int, 5> grades;               // array of student grades
    //    std::array<std::string, 5> studentNames; // array of student names;
};

