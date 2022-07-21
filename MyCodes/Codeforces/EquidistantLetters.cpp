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
        map<char, int> m;
        for(int i = 0; i <s.length(); i++)
            m[s[i]]++;
        for(auto it = m.begin(); it != m.end(); it++)
        {
            if(it->second==2)
                cout<<it->first<<it->first;
            else
                cout<<it->first;
        }
        cout<<endl;
    }
    return 0;
}