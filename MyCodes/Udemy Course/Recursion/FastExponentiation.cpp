#include<bits/stdc++.h>

using namespace std;

int Exponent(int a, int b)
{
    // Base Case
    if(b == 0)
        return 1;
    // Recursive case
    // Fast Exponentiation Method
    int ans = Exponent(a, b/2);
    if(b&1)
        return a*ans*ans;
    else
        return ans*ans; 
}

int main()
{
    int a, b;
    cin>>a>>b;
    cout<<Exponent(a,b)<<endl;
    return 0;
}