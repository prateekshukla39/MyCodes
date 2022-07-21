#include<bits/stdc++.h>

using namespace std;

int FibonacciSeries(int n)
{
    // Base Case
    if(n == 0 || n == 1)
        return n;
    // Recursive Case
    int term = FibonacciSeries(n - 2) + FibonacciSeries(n - 1);
    return term;
}

int main()
{
    int n;
    cin>>n;
    cout<<FibonacciSeries(n);
    return 0;
}