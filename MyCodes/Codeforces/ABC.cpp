#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t,n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        string s;
        cin>>s;
        int c0 = 0, c1 = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
            c0++;
            else
            c1++;
        }
        if(c0>1 || c1>1)
        cout<<"NO";
        else 
        cout<<"YES";
        cout<<endl;
    }
    return 0;
}