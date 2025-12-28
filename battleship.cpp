#include <iostream>

using namespace std;

int main()
{
    // --- GAME VARIABLES ---
    int board[5][5];           // The game grid (5x5 matrix)
    int shipsRemaining = 3;    // Total number of hidden ships
    bool isGameRunning = true; // Control flag for the game loop
    int row, col;              // Variables to store user input

    // --- INITIALIZATION ---
    // Step 1: Clear the board (Set all cells to 0 -> Water)
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            board[i][j] = 0;
        
        }
    }

    // --- PLACE SHIPS ---
    // Step 2: Hide ships at specific coordinates (Hardcoded for now)
    // 1 represents a hidden ship
    board[0][3] = 1;
    board[2][1] = 1;
    board[4][4] = 1;

    // --- WELCOME SCREEN & RULES ---
    // Display instructions to the player
    cout << "========================================" << endl;
    cout << "       BATTLESHIP GAME (C++)            " << endl;
    cout << "========================================" << endl;
    cout << "RULES:" << endl;
    cout << "1. The map is a 5x5 grid." << endl;
    cout << "2. Enter Row and Column numbers between 0 and 4." << endl;
    cout << "3. There are 3 hidden ships. Find them all!" << endl;
    cout << "========================================" << endl;

    // --- GAME LOOP ---
    // The loop continues as long as the game is running
    while (isGameRunning)
    {

        cout << "\nEnter Row and Column (0-4): ";
        cin >> row >> col;

        // --- INPUT VALIDATION (Basic) ---
        // Check if the user already fired at this location
        // Logic: Values > 1 (2 or 3) mean the cell is already revealed
        if (board[row][col] > 1)
        {
            cout << ">> You already fired at this location! Try again." << endl;
            continue; // Skip the rest of the loop and ask for input again
        }

        // --- CHECK FOR HIT ---
        // Logic: Value 1 means there is a ship
        else if (board[row][col] == 1)
        {
            cout << ">> BOOM! Direct HIT!" << endl;

            board[row][col] = 2; // Mark as 'HIT' (2)
            shipsRemaining--;    // Decrease the ship count

            // --- VICTORY CHECK ---
            if (shipsRemaining == 0)
            {
                cout << "\n****************************************" << endl;
                cout << " CONGRATULATIONS! ALL SHIPS DESTROYED!  " << endl;
                cout << "****************************************" << endl;
                break; // Exit the loop, game over
            }
        }

        // --- CHECK FOR MISS ---
        // Logic: Value 0 means empty water
        else
        {
            cout << ">> Splash... You missed." << endl;
            board[row][col] = 3; // Mark as 'MISS' (3)
        }
    }

    cout << "Game Over. Thank you for playing!" << endl;
    return 0;
}