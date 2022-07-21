#include<bits/stdc++.h>

using namespace std;

void printBrackets(string output, int n, int open, int close, int i)
{
    // Base Case
    if(i == 2*n)
    {
        cout<<output<<endl;
        return;
    }
    // Recursive Cases

    // Opening Brackets
    if(open < n)
        printBrackets(output + '(', n, open + 1, close, i + 1);
    // Closing Brackets
    if(close < open)
        printBrackets(output + ')', n, open, close + 1, i + 1);
}

int main()
{
    string output = "";
    int n;
    cin>>n;
    printBrackets(output, n, 0, 0, 0);
    return 0;
}