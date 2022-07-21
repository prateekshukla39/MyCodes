#include<bits/stdc++.h>

using namespace std;

bool isSafe(int m, int n, int i, int j, vector<vector<int>> v, vector<vector<bool>> visited)
{
    if(i < 0 || i >= m || j < 0 || j >= n || v[i][j] == 0 || visited[i][j])
        return false;
    return true;
}

bool solve(int m, int n, int i, int j, vector<vector<int>> v, vector<vector<bool>> visited, int &ans, int len)
{
    // Base case
    if(i == m - 1 && j == n - 1)
    {
        ans = max(len, ans);
        return true;
    }
    // Recursive case
    if(!isSafe(m, n, i, j, v, visited))
        return false;
    visited[i][j] = true;
        // Left
        solve(m, n, i, j - 1, v, visited, ans, len + 1);
        // Right
        solve(m, n, i, j + 1, v, visited, ans, len + 1);
        // Top
        solve(m, n, i - 1, j, v, visited, ans, len + 1);
        // Bottom
        solve(m, n, i + 1, j, v, visited, ans, len + 1);
    visited[i][j] = false;
}

int findLongestPath(int m, int n, vector<vector<int>> v)
{
    //Complete this function. Do not modify the name or parameters. You can make a helper function if needed.
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int ans = 0;
    solve(m, n, 0, 0, v, visited, ans, 0);
    return ans;
}

int main()
{
    int m = 3, n = 3;
    vector<vector<int>> v = {{1, 1, 1},
                             {1, 1, 1},
                             {0, 0, 1}};
    cout<<findLongestPath(m, n, v)<<endl;
    return 0;
}