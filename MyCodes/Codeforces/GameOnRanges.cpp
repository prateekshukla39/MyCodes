#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        map<pair<int,int>, int> m;
        vector<int> l(n), r(n);
        for(int i=0; i<n; i++)
        {
            cin>>l[i]>>r[i];
            m[{l[i], r[i]}] = 1;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=l[i]; j<=r[i]; j++)
            {
                if(l[i] == r[i])
                    cout<<l[i]<<" "<<r[i]<<" "<<j<<endl;
                if(m[{l[i], j-1}]==1 && m[{j+1, r[i]}]==1)
                    cout<<l[i]<<" "<<r[i]<<" "<<j<<endl;
                if(j==l[i] && m[{j+1, r[i]}]==1 || j==r[i] && m[{l[i], j-1}]==1)
                    cout<<l[i]<<" "<<r[i]<<" "<<j<<endl;
            }
        }
    }
    return 0;
}