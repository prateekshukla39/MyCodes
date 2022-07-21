#include <bits/stdc++.h>

using namespace std;

string answer(string &c) 
{
    for(auto &i : c)
    {
        if(i=='U')
        {
            i = 'D';
            continue;
        }
        if(i=='D')
        {
            i = 'U';
            continue;
        }
    }
    return c;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int c;
        string s;
        cin>>c;
        cin>>s;
        cout<<answer(s)<<endl;
    }
    return 0;
}