#include<bits/stdc++.h>

using namespace std;

void solve(int n, int s, int d, int h)
{
    // Base case
    if(n == 1)
    {
        cout<<"Moving form "<<s<<" to "<<d<<endl;
        return;
    }
    // Recursive case
    solve(n - 1, s, h, d);
        cout<<"Moving form "<<s<<" to "<<d<<endl;
    solve(n - 1, h, d, s);
    return;
}

int main()
{
    int n, s = 1, h = 2, d = 3;
    cin>>n;
    solve(n,s,h,d); 
    return 0;
}