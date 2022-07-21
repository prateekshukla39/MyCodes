#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int i = 0, cnt = 0, index;
        while(i<n)
        {
            if(s[i]==s[i+1])
            {
                cnt++;
                i += 2;
            }
            
        }
    }
    return 0;
}