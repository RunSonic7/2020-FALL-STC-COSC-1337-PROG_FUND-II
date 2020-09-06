#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Constants
const int NUM_ROWS = 3; // Number of rows in the gameboard
const int NUM_COLS = 3; // Number of columns in the gameboard
int playerCurrentEntries[2];

void gameBoard(string[][NUM_COLS], int, string[], int, int);
bool validatePlayerEntries(string);

// Function prototypes
int main()
{

   // Variables required
   string playerNames[2];
   string currentPlayerName;
   //   string gameBoardMarks[3][3] = {{"X", "X", "X"}, {"O", "O", "O"}, {"X", "O", "X"}};
   string gameBoardMarks[3][3] = {{" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "}};
   int scoreX = 0;
   int scoreO = 0;

   bool validGameMove = false;
   bool winnerDetermined = false;
   bool isGameAdraw = false;
   string playAgain = "";

   // Start of Game
   cout << "Welcome to Tic-Tac-Toe!\n\n\n";

   // Get names of players.
   cout << "Please provide the Player 1 name (X):  ";
   cin >> playerNames[0];

   cout << "Please provide the Player 2 name (O):  ";
   cin >> playerNames[1];

   // Show Gameboard
   gameBoard(gameBoardMarks, NUM_ROWS, playerNames, scoreX, scoreO);

   // Starting player
   char currentPlayer = 'X';
   currentPlayerName = playerNames[0];

   validatePlayerEntries(currentPlayerName);
   
   return 0;
}

// Validate Player Entries Function
bool validatePlayerEntries(string playerName)
{

   bool validRow = false;
   bool validColumn = false;
   int currentRow = -1;
   int currentColumn = -1;
   string inputRow;
   string inputCol;

   do
   {
      validRow = false;
      validColumn = false;
      currentRow = -1;
      currentColumn = -1;

      cout << playerName << " please select a Row (1-3):  ";
      cin >> inputRow;

      cout << playerName << " please select a Column (1-3):  ";
      cin >> inputCol;
   } while (true);
}

void gameBoard(string array[][NUM_COLS], int numRows, string name[], int Xsc, int Osc)
{
   system("clear");

   cout << "Tic - Tac - Toe Current Board\n"
        << "====== Scores ======\n"
        << name[0] << "  " << Xsc << "   " << Osc << "  " << name[1] << endl
        << "\n    1     2     3"
        << "\n       |     |     "
        << "\n1   " << array[0][0] << "  |  " << array[0][1] << "  |  " << array[0][2] << "  "
        << "\n       |     |     "
        << "\n  -----+-----+-----"
        << "\n       |     |     "
        << "\n1   " << array[1][0] << "  |  " << array[1][1] << "  |  " << array[1][2] << "  "
        << "\n       |     |     "
        << "\n  -----+-----+-----"
        << "\n       |     |     "
        << "\n1   " << array[2][0] << "  |  " << array[2][1] << "  |  " << array[2][2] << "  "
        << "\n       |     |     " << endl;
}