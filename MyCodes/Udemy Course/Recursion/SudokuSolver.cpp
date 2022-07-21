#include<bits/stdc++.h>

using namespace std;

bool canPlace(vector<vector<int> > mat, int no, int x, int y)
{
    int n = 9;
    // Check for Row & Column
    for(int c = 0, r = 0; c < n || r < n; c++, r++)
        if(mat[x][c] == no || mat[r][y] == no) return false;
    // Check for SubGrid
    int sx = (x/3)*3;
    int sy = (y/3)*3;
    for(int i = sx; i < sx + 3; i++)
        for(int j = sy; j < sy + 3; j++)
            if(mat[i][j] == no) return false;

    return true;
}

bool solve(vector<vector<int> > &mat, int i, int j)
{
    // Base Case
    if(i >= 9)
        return true;

    // Recursive Case
    if(j == 9)
        return solve(mat, i + 1, 0);
    // Skipping the prefilled cells
    if(mat[i][j] != 0)
        return solve(mat, i, j + 1);
    // Placing correct Nos in rows (Cell to be filled)
    for(int no = 1; no <= 9; no++)
    {
        // Check Whether No can be placed or not
        if(canPlace(mat, no, i, j))
        {
            mat[i][j] = no;
            bool success = solve(mat, i, j + 1);
            if(success)
                return true;
            // Backtracking
            mat[i][j] = 0;
        }
    }
    return false;
}

vector<vector<int> > solveSudoku(vector<vector<int> > input)
{
    solve(input, 0, 0);
    return input;
}

void printGrid(vector<vector<int> > mat)
{
    cout<<" -------------------------------------"<<endl;
    for(int i = 0; i < 9; i++)
    {
        cout<<" | ";
        for(int j = 0; j < 9; j++)
            cout<<mat[i][j]<<" | ";
        cout<<endl<<" -------------------------------------"<<endl;
    }
}

int main()
{
    int n = 9;
    vector<vector<int> > mat = {{0, 5, 8, 7, 0, 0, 9, 1, 2},
                                {6, 9, 0, 3, 1, 0, 0, 0, 0},
                                {1, 0, 4, 0, 9, 8, 0, 7, 0},
                                {0, 1, 2, 6, 0, 7, 0, 8, 9},
                                {8, 4, 6, 2, 5, 9, 1, 3, 7},
                                {0, 0, 3, 0, 0, 0, 0, 0, 5},
                                {0, 6, 0, 4, 8, 5, 0, 9, 0},
                                {7, 3, 9, 1, 0, 0, 0, 4, 8},
                                {4, 8, 0, 9, 7, 0, 2, 6, 1}};
    mat = solveSudoku(mat);
    printGrid(mat);
    return 0;
}