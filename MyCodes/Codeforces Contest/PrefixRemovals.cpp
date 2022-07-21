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
        unordered_set<char> S;
        map<char, int> m;
        for(int i = 0; i<s.length(); i++)
        {
            S.insert(s[i]);
            m[s[i]]++;
        }
        int index;
        for(int i = 0; i<s.length(); i++)
        {
            if(m[s[i]]==1)
            {
                index = i;
                break;
            }
            else
                m[s[i]]--;
        }
        for(int i = index; i<s.length(); i++)
            cout<<s[i];
        cout<<endl;
    }
    return 0;
}