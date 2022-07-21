#include<bits/stdc++.h>

using namespace std;

int Solve(int n, int k)
{
    // Base case
    if(n == 1 && k == 1)
        return 0;
    // Recursive case
    int mid = pow(2, n - 1)/2;
    if(k <= mid)
        return Solve(n - 1, k);
    else
        return !(Solve(n - 1, k - mid));
}

int main()
{
    int n, k;
    cin>>n>>k;
    cout<<Solve(n, k)<<endl;
    return 0;
}