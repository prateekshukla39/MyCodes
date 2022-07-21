#include<bits/stdc++.h>

using namespace std;

#define int     long long int

signed main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n, sum = 0;
        cin>>n;
        vector<int> v(n), v2;
        unordered_set<int> s;
        for(int i=0; i<n; i++)
        {
            cin>>v[i];
            s.insert(v[i]);
            sum += v[i];
        }
        bool flag = true;
        for(int i=2; i<n/2; i++)
        {
            if(s.find(sum/n) == s.end())
                flag = false;
            sum /= n;
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}