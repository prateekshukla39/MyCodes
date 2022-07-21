#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

int c = 0;

bool canPlace(int n, int mat[][9], int no, int x, int y)
{
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

void printGrid(int n, int mat[][9])
{
    cout<<" -------------------------------------"<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<" | ";
        for(int j = 0; j < n; j++)
            cout<<mat[i][j]<<" | ";
        cout<<endl<<" -------------------------------------"<<endl;
    }
}

bool solveSudoku(int n, int mat[][9], int i, int j)
{
    // Base Case
    if(i >= n)
    {
        // Print Grid
        printGrid(n, mat);
        return true;
    }
    // Recursive Case
    if(j == n)
        return solveSudoku(n, mat, i + 1, 0);
    // Skipping the prefilled cells
    if(mat[i][j] != 0)
        return solveSudoku(n, mat, i, j + 1);
    // Placing correct Nos in rows (Cell to be filled)
    for(int no = 1; no <= n; no++)
    {
        // Check Whether No can be placed or not
        if(canPlace(n, mat, no, i, j))
        {
            mat[i][j] = no;
            bool success = solveSudoku(n, mat, i, j + 1);
            c++;
            if(success)
                return true;
        }
    }    
    // Backtrack
    mat[i][j] = 0;
    return false;
}

int main()
{
    auto start = high_resolution_clock::now();
    int n = 9;
    int mat[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                     {6, 0, 0, 1, 9, 5, 0, 0, 0},
                     {0, 9, 8, 0, 0, 0, 0, 6, 0},
                     {8, 0, 0, 0, 6, 0, 0, 0, 3},
                     {4, 0, 0, 8, 0, 3, 0, 0, 1},
                     {7, 0, 0, 0, 2, 0, 0, 0, 6},
                     {0, 6, 0, 0, 0, 0, 2, 8, 0},
                     {0, 0, 0, 4, 1, 9, 0, 0, 5},
                     {0, 0, 0, 0, 8, 0, 1, 7, 9}};
    if(!solveSudoku(n, mat, 0, 0))
        cout<<"No Solution Exists"<<endl;
    cout<<c<<" Steps"<<endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"Duration : "<<duration.count()/(float)1000000<<"seconds"<<endl;
    return 0;
}