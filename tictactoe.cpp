#include <iostream>
#include <iomanip>

using namespace std;

char box[9] = { '1','2','3','4','5','6','7','8','9' };

int checkAllResult();

void printPlayerBoard();

int main()
{
    int playerNumber = 1;
    int i = 0;
    int chooseMark = 0;
    char markOnBoard;

    cout << "Tic Tac Toe Game" << endl << endl;
    
    cout << "Rules for playing:" << endl;
    cout << "Player 1 starts the game." << endl;
    cout << "Then both players alternate turns." << endl;
    cout << "Both players mark one unmarked box to place their marks." << endl;
    cout << "The objective is for both players to try to put their" << endl;
    cout << "separate markings 3 in a row." << endl;
    cout << "Both players while trying to get their 3 in a row," << endl;
    cout << "try to prevent others from getting 3 in a row." << endl;
    cout << "Whichever player gets 3 in a row first wins and " << endl;
    cout << "the round ends." << endl;
    cout << "If all the boxes have been marked without any player" << endl;
    cout << "getting a 3 in a row, then the game ends and no one wins." << endl;
    cout << endl;

    do {
        printPlayerBoard();

        cout << "Player " << playerNumber << ", enter a number:  ";
        cin >> chooseMark;
        cout << endl;

        if (playerNumber == 1)
        {
            markOnBoard = 'X';
            playerNumber++;
        }
        else
        {
            markOnBoard = 'O';
            playerNumber--;
        }

        if (chooseMark == 1 && box[0] == '1')
            box[0] = markOnBoard;
        else if (chooseMark == 2 && box[1] == '2')
            box[1] = markOnBoard;
        else if (chooseMark == 3 && box[2] == '3')
            box[2] = markOnBoard;
        else if (chooseMark == 4 && box[3] == '4')
            box[3] = markOnBoard;
        else if (chooseMark == 5 && box[4] == '5')
            box[4] = markOnBoard;
        else if (chooseMark == 6 && box[5] == '6')
            box[5] = markOnBoard;
        else if (chooseMark == 7 && box[6] == '7')
            box[6] = markOnBoard;
        else if (chooseMark == 8 && box[7] == '8')
            box[7] = markOnBoard;
        else if (chooseMark == 9 && box[8] == '9')
            box[8] = markOnBoard;
        else
        {
            cout << "Move not possible" << endl;
            cout << "Try again" << endl << endl;

            if (playerNumber == 1)
            {
                playerNumber++;
            }
            else
            {
                playerNumber--;
            }
        }
        
        // check to see if the game is over after every marking
        i = checkAllResult();
    } while (i == -1);

    printPlayerBoard();

    if (playerNumber == 1)
    {
        // If i = 1, then player 1 wins
        // Otherwise the game is a draw
        if (i == 1)
        {
            playerNumber++;
            cout << "Player " << playerNumber << " wins " << endl;
        }
        else
        {
            cout << "Draw Game" << endl;
        }
    }
    // If i = 1, then player 2 wins
    // Otherwise the game is a draw
    else
    {
        if (i == 1)
        {
            playerNumber--;
            cout << "Player " << playerNumber << " wins " << endl;
        }
        else
        {
            cout << "Draw Game" << endl;
        }
    }

    cout << "Press \"enter\" to end program";

    cin.ignore();
    cin.get();

    return 0;
}

void printPlayerBoard()
{
    cout << "Player 1 (X)";
    cout << endl;
    cout << "Player 2 (O)";
    cout << endl << endl;

    cout << setw(6) << "|";
    cout << setw(6) << "|" << endl;

    cout << setw(3) << box[0];
    cout << setw(3) << "|";
    cout << setw(3) << box[1];
    cout << setw(3) << "|";
    cout << setw(3) << box[2] << endl;

    cout << setw(5) << "_____";
    cout << setw(1) << "|";
    cout << setw(5) << "_____";
    cout << setw(1) << "|";
    cout << setw(5) << "_____" << endl;

    cout << setw(6) << "|";
    cout << setw(6) << "|" << endl;

    cout << setw(3) << box[3];
    cout << setw(3) << "|";
    cout << setw(3) << box[4];
    cout << setw(3) << "|";
    cout << setw(3) << box[5] << endl;

    cout << setw(5) << "_____";
    cout << setw(1) << "|";
    cout << setw(5) << "_____";
    cout << setw(1) << "|";
    cout << setw(5) << "_____" << endl;

    cout << setw(6) << "|";
    cout << setw(6) << "|" << endl;

    cout << setw(3) << box[6];
    cout << setw(3) << "|";
    cout << setw(3) << box[7];
    cout << setw(3) << "|";
    cout << setw(3) << box[8] << endl;

    cout << setw(6) << "|";
    cout << setw(6) << "|" << endl;
}

// Function returns current status of the game
// 1 for game is over with a win
// 0 for game is over with no win
// -1 for game is in progress
int checkAllResult()
{
    if (box[0] == box[1] && box[1] == box[2])
        return 1;
    else if (box[3] == box[4] && box[4] == box[5])
        return 1;
    else if (box[6] == box[7] && box[7] == box[8])
        return 1;

    else if (box[0] == box[4] && box[4] == box[8])
        return 1;
    else if (box[2] == box[4] && box[4] == box[6])
        return 1;

    else if (box[0] == box[3] && box[3] == box[6])
        return 1;
    else if (box[1] == box[4] && box[4] == box[7])
        return 1;
    else if (box[2] == box[5] && box[5] == box[8])
        return 1;

    else if (box[0] != '1' && box[1] != '2' && box[2] != '3'
          && box[3] != '4' && box[4] != '5' && box[5] != '6'
          && box[6] != '7' && box[7] != '8' && box[8] != '9')
        return 0;

    else
        return -1;
}
