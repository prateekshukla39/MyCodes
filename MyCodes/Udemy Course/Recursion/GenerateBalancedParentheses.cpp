#include<bits/stdc++.h>

using namespace std;

void solve(int open, int close, string output, vector<string> &v)
{
    // Base Case
    if(open == 0 && close == 0)
    {
        v.push_back(output);
        return;
    }
    // Recursive Case
    if(open != 0)
    {
        string op1 = output;
        op1.push_back('(');
        solve(open - 1, close, op1, v);
    }
    if(close > open)
    {
        string op2 = output;
        op2.push_back(')');
        solve(open, close - 1, op2, v);
    }
    return;
}

vector<string> parentheses(int num)
{
    int open = num;
    int close = num;
    string output = "";
    vector<string> v;
    solve(open, close, output, v);
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