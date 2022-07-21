#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int k = 1;
        for(int i = 0; i < n - 1 && n!=1; i++)
        {
            if(s[i+1]<=s[i])
            {
                k = i + 1;
            }
            else
            {
                k = i;
                break;
            }
        }
        if((n==1)||(s[0]==s[1]))
            k = 0;
        for(int i=0; i<=k; i++)
            cout<<s[i];
        for(int i=k; i>=0; i--)
            cout<<s[i];
        cout<<endl;
    }
    return 0;
}