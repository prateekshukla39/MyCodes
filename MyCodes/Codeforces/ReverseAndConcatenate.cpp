#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        bool flag = false;
        for(int i = 0; i < n/2; i++)
        {
            if(s[i]!=s[n-1-i])
            {
                flag = true;
                break;
            }
        }
        if(!flag || k==0)
            cout<<1<<endl;
        else
            cout<<2<<endl;
    }
    return 0;
}