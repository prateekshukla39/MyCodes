#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        int c0 = 0, c1 = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '0')
            c0++;
            else
            c1++;
        }
        if(c0==c1)
        cout<<c0-1<<endl;
        else 
        cout<<min(c0,c1)<<endl;
    }
    return 0;
}