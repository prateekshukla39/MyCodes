#include<bits/stdc++.h>

using namespace std;

long long int powerModulo(int a, int b)
{
    //Write your code here. Do not modify the function or parameters. Use helper functions if needed.
    // Base Case
    if(b == 0)
        return 1;
    // Recursive case
    // Fast Exponentiation Method
    int ans = powerModulo(a, b/2);
    long long int x = (((ans)%1000000007)*((ans)%1000000007))%1000000007;
    if(b&1)
        return (((a)%1000000007)*(x)%1000000007)%1000000007;
    else
        return x;
}

int main()
{
    int a, b;
    cin>>a>>b;
    cout<<powerModulo(a, b)<<endl;
    return 0;
}