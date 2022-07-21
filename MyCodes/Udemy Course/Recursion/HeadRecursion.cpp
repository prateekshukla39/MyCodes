#include<bits/stdc++.h>

using namespace std;

void Head(int n)
{
    // Base case
    if(n == 0)
        return;
    // Recursive case
    cout<<n<<" ";
    Head(n - 1);
}

int main()
{
    int n;
    cin>>n;
    Head(n);
    return 0;
}