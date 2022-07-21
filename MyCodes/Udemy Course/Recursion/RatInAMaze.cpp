#include<bits/stdc++.h>

using namespace std;

bool calc(int n, vector<vector<char>> c, vector<int> &v, int i, int j)
{
    // Base case
    if(i == n && j == n) 
        return true;
    if(i == n + 1 || j == n + 1) 
        return false;
    // Recursive Case
    // For Down
    if(j != n && c[i][j + 1] != 'X')
    {
        if(calc(n, c, v, i, j + 1))
        {
            v.push_back( (i)*(n + 1) + (j + 2) );
            return true;
        }
    }
    // For Up
    if(i != n && c[i + 1][j] != 'X')
    {
        if(calc(n, c, v, i + 1, j))
        {
            v.push_back((i + 1)*(n + 1) + (j + 1));
            return true;
        }
    }
    return false;
}

vector<int> findPath(int n, vector<vector<char>> c)
{
    vector<int> v;
    calc(n - 1, c, v, 0, 0);
    v.push_back(1);
    reverse(v.begin(), v.end());
    return v;
}

int main()
{
    int n = 4;
    vector<vector<char>> c = {{'O', 'O', 'X', 'O'},
                              {'O', 'X', 'O', 'O'},
                              {'O', 'O', 'O', 'X'},
                              {'X', 'X', 'O', 'O'}};
    auto v = findPath(n, c);
    cout<<v.size()<<endl;
    for(int i : v)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}