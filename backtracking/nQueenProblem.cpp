#include <iostream>
#include <cstring>
using namespace std;

char chess_board[8][8];

//checking safety condition
bool safety_condition(int row, int column, int no_of_queens)
{
    //same column
    for (int i = 0; i < row; i++)
    {
        if (chess_board[i][column] == 'Q')
        {
            return false;
        }
    }
    // same right diagonal 
    for (int i = row, j = column; i >= 0 && j >= 0; i--, j--)
    {
        if (chess_board[i][j] == 'Q')
        {
            return false;
        }
    }
    //same left diagonal
    for (int i = row, j = column; i >= 0 && j < no_of_queens; i--, j++)
    {
        if (chess_board[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}

void backtacking_n_queen(int row, int no_of_queens)
{
    //print the solution
    if (row == no_of_queens)
    {
        for (int i = 0; i < no_of_queens; i++)
        {
            for (int j = 0; j < no_of_queens; j++)
            {
                cout << chess_board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < no_of_queens; i++)
    {
        //safety condition
        if (safety_condition(row, i, no_of_queens))
        {
            //place queen at this position
            chess_board[row][i] = 'Q';
            backtacking_n_queen(row + 1, no_of_queens);
            //bactrack
            chess_board[row][i] = '*';
        }
    }
}

int main()
{
    int no_of_queens;
    cout << "Enter the number of Queens for N-Queen Problem : ";
    cin >> no_of_queens;

    for (int i = 0; i < no_of_queens; i++)
    {
        for (int j = 0; j < no_of_queens; j++)
        {
            chess_board[i][j] = '*';
        }
    }
    backtacking_n_queen(0, no_of_queens);
    return 0;
}
