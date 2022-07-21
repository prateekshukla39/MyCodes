#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int l, r;
    if(v[0]!=1)
    {
    l = 0;
    for(int i = 0; i < n; i++)
    {
        if(v[i]==1)
        r=i;
    }
    for(int i = r; i >=l; i--)
    cout<<v[i]<<" ";
    for(int i = r + 1; i < n; i++)
    cout<<v[i]<<" ";
    }
    else
    {
        l=n-1;
        r=n-1;
    for(int i = 0; i < n; i++)
    {
        if((i<(n-1))&& (v[i+1]!=v[i] + 1))
        {
        l = i + 1;
        break;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(v[i]==v[l-1]+1)
        {
        r = i;
        break;
        }
    }
    for(int i = 0; i < l; i++)
    cout<<v[i]<<" ";
    for(int i = r; i >= l; i--)
    cout<<v[i]<<" ";
    for(int i = r + 1; i < n; i++)
    cout<<v[i]<<" ";
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
    return 0;
}