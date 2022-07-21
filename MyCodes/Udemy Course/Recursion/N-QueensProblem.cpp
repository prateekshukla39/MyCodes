#include<bits/stdc++.h>

using namespace std;

bool canPlace(int n, int board[][20], int x, int y)
{
    // Column
    for (int k = 0; k < x; ++k)
        if(board[k][y] == 1) return false;
    // Left Diagonal
    int i = x;
    int j = y;
    while(i >= 0 && j >= 0)
    {
        if(board[i][j] == 1) return false;
        i--, j--;
    }
    // Right Diagonal
    i = x, j = y;
    while(i >= 0 && j < n)
    {
        if(board[i][j] == 1) return false;
        i--, j++;
    }
    return true;
}

void printBoard(int board[][20], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

bool solveNQueens(int n, int board[][20], int i)
{
    // Base Case
    if(i == n)
    {
        // Print The board
        printBoard(board, n);
        return true;
    }
    // Recursive Case
    // Try to pkace a Queen in every Row
    for(int j = 0; j < n; j++)
    {
        // Whether the current pos is safe or not
        if(canPlace(n, board, i, j))
        {
            board[i][j] = 1;
            bool success = solveNQueens(n, board, i + 1);
            if(success) 
                return true;
            // Backtrack
            board[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    int board[20][20] = {0};
    int n;
    cin>>n;
    solveNQueens(n, board, 0);
    return 0;
}