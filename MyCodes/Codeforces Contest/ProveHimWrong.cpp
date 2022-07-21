#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        if(n>19)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            for(int i=0; i<n; i++)
            {
                int x = pow(3,i);
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}