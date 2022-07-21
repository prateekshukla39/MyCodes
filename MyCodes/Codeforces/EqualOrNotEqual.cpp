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
        int cntN = 0;
        for(int i = 0; i <s.length(); i++)
        {
            if(s[i]=='N')
                cntN++;
        }
        if(cntN == 1)
            cout<<"NO"<<endl;
        else    
            cout<<"YES"<<endl;
    }
    return 0;
}