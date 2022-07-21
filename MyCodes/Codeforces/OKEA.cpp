#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        if(k==1)
        {
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++)
            {
                cout<<i<<endl;
            }
        }
        else if(k>1 && n%2!=0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++)
            {
            for(int j=1;j<=k;j++)
            {
                cout<<(i + (j - 1) * n)<<" ";
            }
            cout<<endl;
            }
        }
    }
    return 0;
}