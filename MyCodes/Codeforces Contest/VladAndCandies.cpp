#include<bits/stdc++.h>

using namespace std;

#define int     long long int

string solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    if(n == 1 && v[n-1] > 1)
        return "NO";
    if(n == 1)
        return "YES";
    sort(v.begin(),v.end());
    if(v[n-1] - v[n-2] <= 1)
        return "YES";
    return "NO";
}

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cout<<solve()<<endl;
    }
    return 0;
}