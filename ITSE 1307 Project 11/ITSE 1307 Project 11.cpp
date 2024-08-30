// Author: Jesus Arias
// GitHub username: ariasje1
// Date: 08/30/2024
// Description: A program that lets the user play the game of Rock, Paper, Scissors against the computer. 
// The user plays against the computer, and the program tracks the number of wins, losses, and ties. 
// The game continues until the user chooses to stop playing.

#include <iostream>
#include <iomanip>
#include <string>
#include <random>
using namespace std;

// Function Prototypes
void game(char play);
int winner(int players_choice, int computers_choice);

int main()
{
    char play;

    // Introduction to the game
    cout << "This program lets the user play the game of Rock, Paper, Scissors against the computer. \n";
    cout << "Rock beats Scissors, paper beats rock, and scissors beats paper. \n";
    cout << "This game can also be played repeatedly and tracks the number of wins and losses.\n" << endl;

    // Prompt user to start the game
    cout << "Would you like to play? (y/n): ";
    cin >> play;

    // Check user response and start the game if 'y'
    if (play == 'Y' || play == 'y')
    {
        game(play);  // Call the game function to start the game loop
    }
    else if (play == 'N' || play == 'n')
    {
        cout << "Have a nice day!\n";
    }
    else
    {
        cout << "Invalid input. Please enter either 'y' or 'n'.\n";
    }

    return 0;
}

/**
 * Function: game
 * --------------
 * Manages the main game loop for playing Rock, Paper, Scissors.
 *
 * Parameters:
 *   play - Character indicating if the user wants to play ('y') or not ('n').
 *
 * The function keeps track of the number of wins for both the player and the computer.
 * It also handles user input, validates it, and displays the results of each round.
 * The game continues to play until the user decides to quit.
 */
void game(char play)
{
    int player_game_wins = 0;     // Player win counter
    int computer_game_wins = 0;   // Computer win counter

    random_device myEngine;   // Random number generator
    uniform_int_distribution<int> randomInt(1, 3);  // Random number distribution from 1 to 3

    // Play loop: continues as long as the user wants to play
    while (play == 'Y' || play == 'y')
    {
        const int Player_Wins = 1,  // Constant representing player win
            Computer_Wins = 2, // Constant representing computer win
            Tie = 3;           // Constant representing a tie

        int result = Tie;  // Initialize result to Tie to start the round

        // Round loop: repeats the round if there is a tie
        while (result == Tie)
        {
            int computers_choice = randomInt(myEngine);  // Generate computer's choice
            int players_choice;  // Variable for player's choice
            string ddash(21, '-');  // Divider for formatting

            // Prompt player to enter their choice
            cout << "\nRock, Paper, Scissors\n" << ddash << "\n1. Rock\n2. Paper\n3. Scissors\n";
            cout << "Enter your choice (1,2,3): ";
            cin >> players_choice;

            // Validate input for player's choice
            if (players_choice < 1 || players_choice > 3)
            {
                cout << "Invalid choice. Please enter 1, 2, or 3.\n";
                continue;  // Skip to the next iteration if invalid input
            }

            // Display the computer's choice
            cout << "\nComputer chose " << computers_choice << "." << endl;

            // Determine winner of the round
            result = winner(players_choice, computers_choice);

            // Update and display the results
            if (result == Player_Wins)
            {
                cout << "Player wins!\n";
                player_game_wins += 1;  // Increment player win counter
            }
            else if (result == Computer_Wins)
            {
                cout << "Computer wins!\n";
                computer_game_wins += 1;  // Increment computer win counter
            }
            else
            {
                cout << "Tie Game! Play again.\n";  // If it's a tie, loop repeats
            }

            // Display the current scores
            cout << "Player: " << setw(6) << player_game_wins << " wins" << endl;
            cout << "Computer: " << setw(4) << computer_game_wins << " wins" << endl;
        }

        // Prompt user if they want to continue playing
        cout << "\nContinue playing? (y,n): ";
        cin >> play;

        // Input validation for continuation
        while (play != 'Y' && play != 'y' && play != 'N' && play != 'n') {
            cout << "Invalid input. Please enter 'y' or 'n': ";
            cin >> play;
        }
    }

    // Print the final scores when the user chooses to stop playing
    cout << "Thank you for playing! Final Scores -> Player: " << player_game_wins << ", Computer: " << computer_game_wins << ".\n";
}

/**
 * Function: winner
 * ----------------
 * Determines the winner of a Rock, Paper, Scissors round.
 *
 * Parameters:
 *   players_choice - The player's choice (1 = Rock, 2 = Paper, 3 = Scissors)
 *   computers_choice - The computer's choice (1 = Rock, 2 = Paper, 3 = Scissors)
 *
 * Returns:
 *   int - 1 if the player wins, 2 if the computer wins, 3 if it is a tie.
 */
int winner(int players_choice, int computers_choice)
{
    const int Rock = 1,     // Constant for Rock
        Paper = 2,    // Constant for Paper
        Scissors = 3; // Constant for Scissors

    // Player wins cases
    if ((players_choice == Rock && computers_choice == Scissors) ||
        (players_choice == Paper && computers_choice == Rock) ||
        (players_choice == Scissors && computers_choice == Paper))
    {
        return 1;  // Player wins
    }
    // Computer wins cases
    else if ((players_choice == Scissors && computers_choice == Rock) ||
        (players_choice == Rock && computers_choice == Paper) ||
        (players_choice == Paper && computers_choice == Scissors))
    {
        return 2;  // Computer wins
    }
    // Tie cases
    else if ((players_choice == Rock && computers_choice == Rock) ||
        (players_choice == Paper && computers_choice == Paper) ||
        (players_choice == Scissors && computers_choice == Scissors))
    {
        return 3;  // Tie
    }

    return 0;  // Default return value (should not reach here with valid input)
}
