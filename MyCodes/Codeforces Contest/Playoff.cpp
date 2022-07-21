#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n;
        if(n==1)
            cout<<n<<endl;
        if(n>1)
        {
            x = pow(2,n)-1;
            cout<<x<<endl;
        }
    }
    return 0;
}