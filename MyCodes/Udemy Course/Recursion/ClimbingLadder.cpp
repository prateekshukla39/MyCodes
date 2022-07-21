#include<bits/stdc++.h>

using namespace std;

int Number_of_ways(int n)
{
    // Base Case
    if(n < 0)
        return 0;
    if(n == 0) 
        return 1;
    // Recursive Case
    int j1 = Number_of_ways(n - 1);
    int j2 = Number_of_ways(n - 2);
    int j3 = Number_of_ways(n - 3);

    return j1 + j2 + j3;
}

int main()
{
    // You can either take a jump of 1, 2 or 3.
    int n = 4;
    cout<<"Number of ways :"<<Number_of_ways(n);
    return 0;
}