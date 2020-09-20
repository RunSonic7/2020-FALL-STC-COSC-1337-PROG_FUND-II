/* Filename: die.h
   Title:  Implemenation File die.h (Instructor provided)
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Due: Sunday, September 20, 2020
   Notes: <cstime> not working, using <ctime> instead
          : instead of ; on Line 25 from template - corrected.
*/

#include <cstdlib>
#include <ctime>

class Die
{
private:
   int sideUp;
   int sides;

public:
   Die();
   Die(int);
   void roll();
   int returnSideUp();
};

Die::Die()
{
   srand(time(0));
   sides = 6;
   sideUp = rand() % sides + 1;
}
Die::Die(int s)
{
   srand(time(0));
   if (s < 2)
      sides = 6;
   else
      sides = s;
   sideUp = rand() % sides + 1;
}

void Die::roll()
{
   sideUp = rand() % sides + 1;
}

int Die::returnSideUp()
{
   return sideUp;
}