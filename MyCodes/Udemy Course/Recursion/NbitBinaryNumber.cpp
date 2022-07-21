#include<bits/stdc++.h>

using namespace std;

void solve(int ones, int zeros, int num, string output, vector<string> &v)
{
    // Base Case
    if(num == 0)
    {
        v.push_back(output);
        return;
    }
    // Recursive Case
    string op1 = output;
    op1.push_back('1');
    solve(ones + 1, zeros, num - 1, op1, v);
    if(ones > zeros)
    {
        string op2 = output;
        op2.push_back('0');
        solve(ones, zeros + 1, num - 1, op2, v);
    }
    return;
}

vector<string> parentheses(int num)
{
    int ones = 0;
    int zeros = 0;
    string output = "";
    vector<string> v;
    solve(ones, zeros, num, output, v);
    return v;
}

int main()
{
    int num = 3;
    auto result = parentheses(num);
    for(auto ch : result)
        cout << ch << endl;
    cout << endl;
    return 0;
}