#include<bits/stdc++.h>

using namespace std;

#define int     long long int

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, B, x, y;
        cin>>n>>B>>x>>y;
        int sum = 0;
        vector<int> v(n+1);
        v[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            if(v[i-1]+x>B)
                v[i] = v[i-1]-y;
            else
                v[i] = v[i-1]+x;
        }
        for(int i = 0; i <= n; i++)
            sum += v[i];
        cout<<sum<<endl;
    }
    return 0;
}