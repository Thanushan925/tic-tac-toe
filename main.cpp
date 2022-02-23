/*---------------------------------------------------------------------------
Author: Thanushan Satheeskumar (FlamingNinja925)

Project: Tic Tac Toe
Date Created: January 6, 2022
Date Last Modified: January 9, 2022

Description: Basic Tic Tac Toe game with two player functionality, as well as
             a visual board.
---------------------------------------------------------------------------*/

#include <iostream>
#include <string>

using namespace std;

//Description: Clears the output screen
//Parameters: N/A
//Returns: N/A
void clearScreen() {
    cout << "\033[2J\033[1;1H";

    return;
}

//Description: Clears the screen, then displays the company's intro
//Parameters: N/A
//Returns: N/A
void displayCompanyIntro() {
    clearScreen();

    cout << "----------------------------------------------\n";
    cout << "\tWelcome to Flaming Ninja Inc.\n";
    cout << "----------------------------------------------\n\n";

    return;
}

//Description: Asks the user to press a key to continue
//Parameters: N/A
//Returns: N/A
void pressToContinue() {
    cout << "Press [ENTER] to Continue...\n";
    cin.ignore();

    return;
}

//Description: Checks to see the status of the game
//Parameters: A char array with the values of the Tic Tac Toe board
//Returns: An int value representing the status of the game
int gameStatus(char board[]) {

    //The following is to check if anyone has won
    if (board[1] == board[2] && board[2] == board[3]) {
        return 1;
    }
    else if (board[4] == board[5] && board[5] == board[6]) {
        return 1;
    }
    else if (board[7] == board[8] && board[8] == board[9]) {
        return 1;
    }
    else if (board[1] == board[4] && board[4] == board[7]) {
        return 1;
    }
    else if (board[2] == board[5] && board[5] == board[8]) {
        return 1;
    }
    else if (board[3] == board[6] && board[6] == board[9]) {
        return 1;
    }
    else if (board[1] == board[5] && board[5] == board[9]) {
        return 1;
    }
    else if (board[3] == board[5] && board[5] == board[7]) {
        return 1;
    }

    //The following is to check if the game is over and nobody won
    else if (board[1] != '1' && board[2] != '2' && board[3] != '3' && 
                board[4] != '4' && board[5] != '5' && board[6] != '6' && 
                board[7] != '7' && board[8] != '8' && board[9] != '9') {
        return 0;
    }

    //The following is to check if the game is still in progress
    else {
        return -1;
    }
}

//Description: Displays the Company Intro, as well as the Tic Tac Toe board with the current values
//Parameters: A char array with the values of the Tic Tac Toe board
//Returns: N/A
void displayBoard(char board[]) {
    displayCompanyIntro();

    cout << "Player 1 (X)   vs.   Player 2 (O)\n\n";

    cout << "\t     |     |     \n";
    cout << "\t  " << board[1] << "  |  " << board[2] << "  |  " << board[3] << "\n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << board[4] << "  |  " << board[5] << "  |  " << board[6] << "\n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << board[7] << "  |  " << board[8] << "  |  " << board[9] << "\n";
    cout << "\t     |     |     \n\n";

    return;
}

int main() {
    char board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int currentPlayer = 1, currentStatus = -1, playerOption;
    char currentSymbol;

    while (currentStatus == -1) {
        displayBoard(board);

        cout << "Player " << currentPlayer << ", Where do you want to mark: ";
        cin >> playerOption;

        if (currentPlayer == 1) {
            currentSymbol = 'X';
        }
        else {
            currentSymbol = 'O';
        }

        if (playerOption == 1 && board[1] == '1') {
            board[1] = currentSymbol;
        }
        else if (playerOption == 2 && board[2] == '2') {
            board[2] = currentSymbol;
        }
        else if (playerOption == 3 && board[3] == '3') {
            board[3] = currentSymbol;
        }
        else if (playerOption == 4 && board[4] == '4') {
            board[4] = currentSymbol;
        }
        else if (playerOption == 5 && board[5] == '5') {
            board[5] = currentSymbol;
        }
        else if (playerOption == 6 && board[6] == '6') {
            board[6] = currentSymbol;
        }
        else if (playerOption == 7 && board[7] == '7') {
            board[7] = currentSymbol;
        }
        else if (playerOption == 8 && board[8] == '8') {
            board[8] = currentSymbol;
        }
        else if (playerOption == 9 && board[9] == '9') {
            board[9] = currentSymbol;
        }
        else {
            cout << "Invalid Value! Please Try Again.\n";

            if (currentPlayer == 1) {
                currentPlayer = 2;
            }
            else {
                currentPlayer = 1;
            }

            pressToContinue();
            cin.ignore();
        }

        currentStatus = gameStatus(board);

        if (currentPlayer == 1) {
            currentPlayer = 2;
        }
        else {
            currentPlayer = 1;
        }
    }

    displayBoard(board);

    if (currentStatus == 1) {
        cout << "Player " << currentPlayer << " wins!" << endl;
    }
    else {
        cout << "Tie Game!" << endl;
    }

    pressToContinue();

    return 0;
}