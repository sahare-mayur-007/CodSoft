#include <iostream>

using namespace std;

char brd[3][3]; 
bool gameOver = false;
char cp = 'O';

void drawBoard() 
{
    cout << " " << brd[0][0] << " | " << brd[0][1] << " | " << brd[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << brd[1][0] << " | " << brd[1][1] << " | " << brd[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << brd[2][0] << " | " << brd[2][1] << " | " << brd[2][2] << endl;
}

void playerMove() 
{
    int row, col;
    cout << "Player " << cp << ", enter row and column (1-3): ";
    cin >> row >> col;

    row--;
    col--;

    if (row < 0 || row > 2 || col < 0 || col > 2) 
    {
        cout << "Invalid, try again" << endl;
        playerMove();
    } 
    else if (brd[row][col] != ' ') 
    {
        cout << "Space already given , try again" << endl;
        playerMove();
    } 
    else 
    {
        brd[row][col] = cp;
    }
}

bool chkWin() 
{
      // Check columns
    for (int i = 0; i < 3; i++) 
    {
        if (brd[0][i] == cp && brd[1][i] == cp && brd[2][i] == cp) 
        {
            return true;
        }
    }

    // Check rows
    for (int i = 0; i < 3; i++) 
    {
        if (brd[i][0] == cp && brd[i][1] == cp && brd[i][2] == cp) 
        {
            return true;
        }
    }

    // Check diagonals
    if (brd[0][0] == cp && brd[1][1] == cp && brd[2][2] == cp) 
    {
        return true;
    }
    if (brd[0][2] == cp && brd[1][1] == cp && brd[2][0] == cp)
    {
        return true;
    }

    return false;
}

bool chkDrw() 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (brd[i][j] == ' ') 
            {
                return false;
            }
        }
    }
    return true;
}

int main() 
{
    
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            brd[i][j] = ' ';
        }
    }

    while (!gameOver) 
    {
        drawBoard(); 
        playerMove();

        if (chkWin()) 
        {
            drawBoard();
            cout << "Player " << cp << " wins!" << endl;
            gameOver = true;
        } 
        else if (chkDrw()) 
        {
            drawBoard();
            cout << "It's a draw!" <<endl;
            gameOver = true;
        }

        cp = (cp == 'O') ? 'X' : 'O'; //Switches the current player.

    }

    return 0;
}
