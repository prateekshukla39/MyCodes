#include<bits/stdc++.h>

using namespace std;

#define int     long long int

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            cin>>v[i];
        sort(v.begin(), v.end());
        cout<<v[n-1]+v[n-2]<<endl;
    }
    return 0;
}