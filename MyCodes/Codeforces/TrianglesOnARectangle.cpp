#include<bits/stdc++.h>

using namespace std;

#define int     long long int

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int w, h, k;
        cin>> w>> h;
        vector<int> H0, Hh, V0, Vw;
        cin>>k;
        for(int i=0; i<k; i++)
        {
            int x;
            cin>>x;
            H0.push_back(x);
        }
        cin>>k;
        for(int i=0; i<k; i++)
        {
            int x;
            cin>>x;
            Hh.push_back(x);
        }
        cin>>k;
        for(int i=0; i<k; i++)
        {
            int x;
            cin>>x;
            V0.push_back(x);
        }
        cin>>k;
        for(int i=0; i<k; i++)
        {
            int x;
            cin>>x;
            Vw.push_back(x);
        }
        int h0, h1, v0, v1;
        h0 = (H0[H0.size()-1]-H0[0])*h;
        h1 = (Hh[Hh.size()-1]-Hh[0])*h;
        v0 = (V0[V0.size()-1]-V0[0])*w;
        v1 = (Vw[Vw.size()-1]-Vw[0])*w;
        int ans = max({h0, h1, v0, v1});
        cout<<ans<<endl;
    }
    return 0;
}