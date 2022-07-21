#include<bits/stdc++.h>

using namespace std;

#define int     long long int

signed main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> v(n), cpy(n);
        map<int, int> m;  
        int eqLen = 1;       
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
            m[v[i]]++;
            eqLen = max(eqLen, m[v[i]]);
        }
        cpy = v;
               
        int cnt = 0, cntr = eqLen;

        while(cntr < n)
        {
            cnt++;
            cntr *= 2;
        }
        
        int swaps = n - eqLen + cnt;
        cout<<swaps<<endl;
    }
    return 0;
}