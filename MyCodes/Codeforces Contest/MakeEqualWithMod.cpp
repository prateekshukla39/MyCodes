#include<bits/stdc++.h>

using namespace std;

#define int       long long int

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        bool flag = false, flag1 = false;
        for(int i=0; i<n; i++)
        {
            cin>>v[i];
            if(v[i]==1)
                flag1 = true; 
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n-1; i++)
        {
            if(v[i+1]-v[i]==1)
                flag = true;
        }
        if(!flag || !flag1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}