/*
    Week 9 - Final Project - Tic-Tac-Toe Game (Comprehensive)
    Name: Juan Mireles II
    Course: CITP 3310.V20 - Survey of Programming Languages
    Semester: Summer III 2019
    Due Date: Wednesday, August 7, 2019 at 11:59PM CDT
*/

using System;

namespace wk9FinalProject
{
    enum Player
    {
        X = 0,
        O = 1,
    }

    class Program
    {
        static void Main(string[] args)
        {
            // Generate Needed Variables
          //  string[] playerNames = new string[2];
        //    string[,] gameBoardMarks = new string[3, 3];
            int currentRow = -1;
            int currentColumn = -1;
            int scoreX = 0;
            int scoreO = 0;
            bool validGameMove = false;
            bool winnerDetermined = false;
            bool isGameAdraw = false;
            string playAgain = "";

            // Fill gameBoardMarks with no value, space.
            gameBoardMarks = resetGameBoard(gameBoardMarks);

            // Start of Game
            Console.WriteLine("Welcome to Tic-Tac-Toe!\n\n\n");

            // Get names of players.
            Console.Write("Please provide the Player 1 name (X):  ");
            playerNames[0] = Console.ReadLine();

            Console.Write("Please provide the Player 2 name (O):  ");
            playerNames[1] = Console.ReadLine();

            // Show GameBoard
            gameBoard(gameBoardMarks, playerNames, scoreX, scoreO);

            // Starting Player
            string currentPlayer = "X";
            int playerIndex = 0;  // To ID X and player name



            // Play Again Loop
            do
            {   // Winner Loop
                do
                {
                    // Determine if User Input is Valid and add to Game Board, loop until valid
                    do
                    {
                        Tuple<int, int> validEntries = validatePlayerEntries(playerIndex, playerNames);
                        currentRow = validEntries.Item1;
                        currentColumn = validEntries.Item2;

                        if (gameBoardMarks[currentRow - 1, currentColumn - 1] == " ")
                        {
                            gameBoardMarks[currentRow - 1, currentColumn - 1] = currentPlayer;
                            validGameMove = true;
                            gameBoard(gameBoardMarks, playerNames, scoreX, scoreO);
                        }
                        else
                        {
                            Console.WriteLine("Sorry but that spot is taken, please make another selection.");
                        }
                    } while (validGameMove == false);

                    // Reset valid Game Move, check if winner, check if draw
                    validGameMove = false;
                    winnerDetermined = checkIfWinnderDetermined(gameBoardMarks, currentPlayer);

                    // Determine if game is a draw
                    isGameAdraw = checkIfDraw(gameBoardMarks);
                    if (isGameAdraw == true)
                    {
                        if (winnerDetermined == true)
                        {
                            isGameAdraw = false;
                        }
                        else
                        {
                            break;
                        }
                    }

                    // Switch player X=>O or O=>X
                    if (winnerDetermined == false)
                    {
                        currentPlayer =
                            currentPlayer == "X" ? currentPlayer = "O"
                                                 : currentPlayer = "X";

                        playerIndex =
                            playerIndex == (int)Player.X ? playerIndex = 1
                                                         : playerIndex = 0;
                    }
                } while (winnerDetermined == false);

                // Winner and not a draw
                if (winnerDetermined == true && isGameAdraw == false)
                {
                    if (currentPlayer == "X")
                    {
                        scoreX++;
                    }
                    else
                    {
                        scoreO++;
                    }
                    gameBoard(gameBoardMarks, playerNames, scoreX, scoreO);
                    Console.WriteLine($"Congrats {playerNames[playerIndex]} You Win!");
                }

                // Game is a draw
                if (isGameAdraw == true)
                {
                    Console.WriteLine($"Game is a Draw.  Well Played {playerNames[0]} and {playerNames[1]}.");
                }

                // Play again?
                Console.Write("Would you like to play again? Enter Y or y for Yes.  Anykey for No: ");
                playAgain = Console.ReadLine();

                // Check input from user if they want to play again.
                if (playAgain == "Y" || playAgain == "y")
                {

                    currentPlayer =
                        currentPlayer == "X" ? currentPlayer = "O"
                                             : currentPlayer = "X";

                    playerIndex =
                        playerIndex == (int)Player.X ? playerIndex = 1
                                                     : playerIndex = 0;

                    resetGameBoard(gameBoardMarks);
                    gameBoard(gameBoardMarks, playerNames, scoreX, scoreO);
                }
            } while (playAgain == "Y" || playAgain == "y");
        }

        static string[,] resetGameBoard(string[,] gameBoard)
        {
            for (int row = 0; row < 3; row++)
            {
                for (int column = 0; column < 3; column++)
                {
                    gameBoard[row, column] = " ";
                }
            }
            return gameBoard;
        }
        static Tuple<int, int> validatePlayerEntries(int playerIndex, string[] playerNames)
        {
            bool validRow = false;
            bool validColumn = false;
            int currentRow = -1;
            int currentColumn = -1;

            do
            {
                validRow = false;
                validColumn = false;
                currentRow = -1;
                currentColumn = -1;

                Console.Write($"{playerNames[playerIndex]}, please select a Row:  ");
                string inputRow = Console.ReadLine();

                Console.Write($"Please select a Column:  ");
                string inputColumn = Console.ReadLine();

                // Validate Row Input
                if (int.TryParse(inputRow, out int inputRowParsed))
                    if (inputRowParsed >= 1 && inputRowParsed <= 3)
                    {
                        validRow = true;
                        currentRow = inputRowParsed;
                    }
                    else
                        Console.WriteLine("Row input is invalid.  Please reenter. ");
                else
                    Console.WriteLine("Row input is invalid.  Please reenter. ");

                // Validate Column Input
                if (int.TryParse(inputColumn, out int inputColumnParsed))
                    if (inputColumnParsed >= 1 && inputColumnParsed <= 3)
                    {
                        validColumn = true;
                        currentColumn = inputColumnParsed;
                    }
                    else
                        Console.WriteLine("Row input is invalid.  Please reenter. ");
                else
                    Console.WriteLine("Column input is invalid.  Please reenter. ");
            } while (validRow == false || validColumn == false);

            return Tuple.Create(currentRow, currentColumn);
        }

        static bool checkIfWinnderDetermined(string[,] gameBoard, string playerCode)
        {
            if ((gameBoard[0, 0] == playerCode && gameBoard[0, 1] == playerCode && gameBoard[0, 2] == playerCode) ||
                (gameBoard[1, 0] == playerCode && gameBoard[1, 1] == playerCode && gameBoard[1, 2] == playerCode) ||
                (gameBoard[2, 0] == playerCode && gameBoard[2, 1] == playerCode && gameBoard[2, 2] == playerCode) ||
                (gameBoard[0, 0] == playerCode && gameBoard[1, 0] == playerCode && gameBoard[2, 0] == playerCode) ||
                (gameBoard[0, 1] == playerCode && gameBoard[1, 1] == playerCode && gameBoard[2, 1] == playerCode) ||
                (gameBoard[0, 2] == playerCode && gameBoard[1, 2] == playerCode && gameBoard[2, 2] == playerCode) ||
                (gameBoard[0, 0] == playerCode && gameBoard[1, 1] == playerCode && gameBoard[2, 2] == playerCode) ||
                (gameBoard[0, 2] == playerCode && gameBoard[1, 1] == playerCode && gameBoard[2, 0] == playerCode))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        static bool checkIfDraw(string[,] gameBoard)
        {
            bool isGameDraw = true;
            for (int row = 0; row < 3; row++)
            {
                for (int column = 0; column < 3; column++)
                {
                    if (gameBoard[row, column] == " ")
                    {
                        isGameDraw = false;
                        break;
                    }
                }
            }
            return isGameDraw;
        }

        static void gameBoard(string[,] gameData, string[] playerNames, int scoreX, int scoreO)
        {
            Console.Clear();
            Console.WriteLine("Tic - Tac - Toe Current Board\n");
            Console.WriteLine("====== Scores ======");
            Console.WriteLine($"{playerNames[0]}  {scoreX}    {scoreO}  {playerNames[1]}\n");
            Console.WriteLine($"    1     2     3");
            Console.WriteLine($"       |     |     ");
            Console.WriteLine($"1   {gameData[0, 0]}  |  {gameData[0, 1]}  |  {gameData[0, 2]}  ");
            Console.WriteLine($"       |     |     ");
            Console.WriteLine($"  -----+-----+-----");
            Console.WriteLine($"       |     |     ");
            Console.WriteLine($"2   {gameData[1, 0]}  |  {gameData[1, 1]}  |  {gameData[1, 2]}  ");
            Console.WriteLine($"       |     |     ");
            Console.WriteLine($"  -----+-----+-----");
            Console.WriteLine($"       |     |     ");
            Console.WriteLine($"3   {gameData[2, 0]}  |  {gameData[2, 1]}  |  {gameData[2, 2]}  ");
            Console.WriteLine($"       |     |     ");
            Console.WriteLine();
        }
    }
}