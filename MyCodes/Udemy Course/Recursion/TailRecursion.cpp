#include<bits/stdc++.h>

using namespace std;

void Tail(int n)
{
    // Base case
    if(n == 0)
        return;
    // Recursive case
    Tail(n - 1);
    cout<<n<<" ";
}

int main()
{
    int n;
    cin>>n;
    Tail(n);
    return 0;
}