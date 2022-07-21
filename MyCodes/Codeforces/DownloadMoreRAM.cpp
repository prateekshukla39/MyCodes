#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++)
            cin>>a[i];
        for(int i=0; i<n; i++)
            cin>>b[i];
        vector<pair<int, int>> p(n);
        for(int i=0; i<n; i++)
        {
            p[i].first = a[i];
            p[i].second = b[i];
        }
        sort(p.begin(), p.end());
        for(int i=0; i<n; i++)
        {
            if(p[i].first<=k)
                k += p[i].second;
            else
                break;
        }
        cout<<k<<endl;
    }
    return 0;
}