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
        set<char> S;
        int count = 0;
        for(int i = 0; s[i]!='\0'; i++)
        {
            if(S.find(s[i]+32)!=S.end())
                count++; 
            S.insert(s[i]);               
        }
        if(count == 3)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}