/* Filename: ticTacToe.cpp
   Title:  Tic-Tac-Toe Game
   
   Name: Juan Mireles II
   Course: COSC 1337.V01 - Programming Fundamentals II
   Term: Fall 2020
   Institution: South Texas College
   Instructor: Mr. Joseph Perez
   Date: Sunday, September 6, 2020
   Due: Sunday, September 6, 2020 at 11:59PM CDT
   Notes: Game without use of Classes or Structs
*/
#include <iostream>
#include <string>
using namespace std;

// Constants
const int NUM_ROWS = 3; // Number of rows in the gameboard
const int NUM_COLS = 3; // Number of columns in the gameboard
int playerCurrentRow;
int playerCurrentColumn;

// Function Prototypes
void gameBoard(char[][NUM_COLS], int, string[], int, int);
void validatePlayerEntries(string);
bool checkIfWinnerDetermined(char[][NUM_COLS], char);
bool checkIfDraw(char[][NUM_COLS]);
void resetGameBoard(char[][NUM_COLS]);

// Function prototypes
int main()
{

   // Variables
   bool validGameMove = false;
   bool winnerDetermined = false;
   bool isGameAdraw = false;
   char gameBoardMarks[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
   char playAgain = ' ';
   int scoreX = 0;
   int scoreO = 0;
   string playerNames[2];
   string currentPlayerName;

   // Start of Game
   system("clear");
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

   do
   {
      // Play Again Loop
      do
      {
         // Winner Loop
         do
         { // Determine if User Input is Valid and add to Game Board, loop until valid
            validatePlayerEntries(currentPlayerName);

            if (gameBoardMarks[playerCurrentRow - 1][playerCurrentColumn - 1] == ' ')
            {
               gameBoardMarks[playerCurrentRow - 1][playerCurrentColumn - 1] = currentPlayer; // Plot Mark
               validGameMove = true;                                                          // Valid Move
               gameBoard(gameBoardMarks, NUM_ROWS, playerNames, scoreX, scoreO);              // Show Gameboard
            }
            else
            {
               cout << "Sorry but that spot is taken, please make another selection.\n";
            }
         } while (validGameMove == false);

         // Reset valid Game Move, check if winner, check if draw
         validGameMove = false;
         winnerDetermined = checkIfWinnerDetermined(gameBoardMarks, currentPlayer);
         isGameAdraw = checkIfDraw(gameBoardMarks);

         // Verify if real draw or board is full with winner
         if (isGameAdraw == true)
         {
            if (winnerDetermined == true)
            {
               isGameAdraw = false;
            }
            else
            {
               cout << "Aww shucks! Nobody won this round!\n";
               break;
            }
         }

         // Switch player X => O or O => X
         if (winnerDetermined == false)
         {
            if (currentPlayer == 'X')
            {
               currentPlayer = 'O';
               currentPlayerName = playerNames[1];
            }
            else
            {
               currentPlayer = 'X';
               currentPlayerName = playerNames[0];
            }
         }
      } while (winnerDetermined == false);

      // Winner and not a draw, increase score for winner
      if (winnerDetermined == true && isGameAdraw == false)
      {
         if (currentPlayer == 'X')
         {
            scoreX++;
         }
         else
         {
            scoreO++;
         }

         // Show Gameboard and Congrats to winner!
         gameBoard(gameBoardMarks, NUM_ROWS, playerNames, scoreX, scoreO);
         cout << "Congrats " << currentPlayerName << " You Win!\n\n";
      }

      // Play again?
      cout << "Would you like to play again? \nEnter Y or y for Yes.  Anykey for No: ";
      cin >> playAgain;

      // Check input from user if they want to play again.
      if (playAgain == 'Y' || playAgain == 'y')
      {
         // Switch to next player mark
         if (currentPlayer == 'X')
         {
            currentPlayer = 'O';
            currentPlayerName = playerNames[1];
         }
         else
         {
            currentPlayer = 'X';
            currentPlayerName = playerNames[0];
         }

         // Reset board to play again
         resetGameBoard(gameBoardMarks);
         // Show Gameboard
         gameBoard(gameBoardMarks, NUM_ROWS, playerNames, scoreX, scoreO);
      }
   } while (playAgain == 'Y' || playAgain == 'y');

   return 0;
}

// Reset Game Board
void resetGameBoard(char mark[][NUM_COLS])
{
   for (int row = 0; row < 3; row++)
   {
      for (int column = 0; column < 3; column++)
      {
         mark[row][column] = ' ';
      }
   }
}

// Check if game has ended in a draw
bool checkIfDraw(char marks[][NUM_COLS])
{
   bool isGameDraw = true;
   for (int row = 0; row < 3; row++)
   {
      for (int column = 0; column < 3; column++)
      {
         if (marks[row][column] == ' ')
         {
            isGameDraw = false;
            break;
         }
      }
   }
   return isGameDraw;
}

// Determine if a player has won
bool checkIfWinnerDetermined(char marks[][NUM_COLS], char currentPlayer)
{

   if ((marks[0][0] == currentPlayer && marks[0][1] == currentPlayer && marks[0][2] == currentPlayer) ||
       (marks[1][0] == currentPlayer && marks[1][1] == currentPlayer && marks[1][2] == currentPlayer) ||
       (marks[2][0] == currentPlayer && marks[2][1] == currentPlayer && marks[2][2] == currentPlayer) ||
       (marks[0][0] == currentPlayer && marks[1][0] == currentPlayer && marks[2][0] == currentPlayer) ||
       (marks[0][1] == currentPlayer && marks[1][1] == currentPlayer && marks[2][1] == currentPlayer) ||
       (marks[0][2] == currentPlayer && marks[1][2] == currentPlayer && marks[2][2] == currentPlayer) ||
       (marks[0][0] == currentPlayer && marks[1][1] == currentPlayer && marks[2][2] == currentPlayer) ||
       (marks[0][2] == currentPlayer && marks[1][1] == currentPlayer && marks[2][0] == currentPlayer))
   {
      return true;
   }
   else
   {
      return false;
   }
}

// Validate Player Entries Function
void validatePlayerEntries(string playerName)
{

   bool validRow = false;
   bool validColumn = false;
   int currentRow = -1;
   int currentColumn = -1;
   int inputRow = -1;
   int inputColumn = -1;

   do
   {
      validRow = false;
      validColumn = false;
      currentRow = -1;
      currentColumn = -1;

      cout << playerName << " please select a Row (1-3):  ";
      cin >> inputRow;

      cout << playerName << " please select a Column (1-3):  ";
      cin >> inputColumn;

      // Validate Row Input
      if (inputRow >= 1 && inputRow <= 3)
      {
         validRow = true;
         currentRow = inputRow;
      }
      else
      {
         cout << "Row Input is invalid. Please re-enter your game selection slot.\n";
      }

      // Validate Column Input
      if (inputColumn >= 1 && inputColumn <= 3)
      {
         validColumn = true;
         currentColumn = inputColumn;
      }
      else
      {
         cout << "Column Input is invalid. Please re-enter your game selection slot.\n\n";
      }
   } while (validRow == false || validColumn == false); // Loop until both true

   // Assign Player Entries to Array
   playerCurrentRow = inputRow;
   playerCurrentColumn = inputColumn;
}

// Display game board to player
void gameBoard(char array[][NUM_COLS], int numRows, string name[], int Xsc, int Osc)
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
        << "\n2   " << array[1][0] << "  |  " << array[1][1] << "  |  " << array[1][2] << "  "
        << "\n       |     |     "
        << "\n  -----+-----+-----"
        << "\n       |     |     "
        << "\n3   " << array[2][0] << "  |  " << array[2][1] << "  |  " << array[2][2] << "  "
        << "\n       |     |     " << endl;
}