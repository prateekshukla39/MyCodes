#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>> t;
    while (t--)
    {
        string s;
        cin>> s;
        char c;
        cin>> c;
        bool place = false;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]==c)
            {
               if(i%2==0)
               place = true;
            }
        }
        if(place)
        cout<<"YES"<<endl;
        else 
        cout<<"NO"<<endl;
    }
    return 0;
}