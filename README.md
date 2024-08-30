# Rock, Paper, Scissors Game

## Overview

This C++ program allows the user to play the classic game of Rock, Paper, Scissors against the computer. The game follows the traditional rules where rock beats scissors, scissors beats paper, and paper beats rock. If both players make the same choice, the game must be replayed until there is a winner. The program keeps track of wins by the player and the computer, as well as the number of ties. After each round, the user is asked if they want to continue playing. The program continues running until the user chooses to quit.

## Program Functionality

The program is divided into several functions to handle different tasks, as follows:

1. **Random Number Generation**:
   - At the beginning of each round, a random number is generated between 1 and 3.
   - This number determines the computer's choice:
     - If the number is `1`, the computer chooses **rock**.
     - If the number is `2`, the computer chooses **paper**.
     - If the number is `3`, the computer chooses **scissors**.
   - The computer's choice is not displayed immediately.

2. **User Input**:
   - The user is prompted to enter their choice of **rock**, **paper**, or **scissors** by selecting `1`, `2`, or `3` from a menu.

3. **Display Choices**:
   - After the user has entered their choice, the computer's choice is displayed.

4. **Determine the Winner**:
   - A winner is selected based on the following rules:
     - **Rock** smashes **scissors**.
     - **Scissors** cut **paper**.
     - **Paper** wraps **rock**.
   - If both players make the same choice, it is a tie, and the game is replayed until there is a winner.

5. **Track Scores**:
   - The program keeps track of the number of wins by the computer, the number of wins by the player, and the number of ties.
   - A running total is displayed after each round.

6. **Continue Playing**:
   - After each round, the user is asked if they want to continue playing. The game continues until the user chooses to quit.

## Example Program Output

```plaintext
This program lets the user play the game of Rock, Paper, Scissors against the computer. 
Rock beats Scissors, paper beats rock, and scissors beats paper. 
This game can also be played repeatedly and tracks the number of wins and losses.

Would you like to play? (y/n): y

Rock, Paper, Scissors
---------------------
1. Rock
2. Paper
3. Scissors
Enter your choice (1,2,3): 1

Computer chose 2.
Computer wins!

Player:      0 wins
Computer:    1 wins

Continue playing? (y,n): n

Thank you for playing! Final Scores -> Player: 0, Computer: 1.
