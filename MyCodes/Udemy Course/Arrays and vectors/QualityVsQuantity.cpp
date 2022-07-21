#include<bits/stdc++.h>

using namespace std;

#define  int        long long int

string solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
    sort(v.begin(), v.end());
    int blue = v[0] + v[1], red = v[n-1];
    bool flag = false;
    int l = 2, r = n - 2;
    while(l<r)
    {
        if(red>blue)
        {
            flag = true;
            break;
        }
        blue += v[l], red += v[r];
        l++,r--;
    }
    if(flag || red>blue)
        return "YES";
    else
        return "NO";
}

signed main()
{
    int t;
    cin>>t;
    while (t--)
    {
        cout<<solve()<<endl;
    }
    return 0;
}