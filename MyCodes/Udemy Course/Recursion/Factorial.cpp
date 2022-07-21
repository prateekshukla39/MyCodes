#include<bits/stdc++.h>

using namespace std;

int Factorial(int n)
{
    // Base case
    if(n <= 1)
        return 1;
    // Recursive case
    int fact = n*(Factorial(n - 1));
    return fact;
}

int main()
{
    int n;
    cin>>n;
    cout<<Factorial(n);
    return 0;
}