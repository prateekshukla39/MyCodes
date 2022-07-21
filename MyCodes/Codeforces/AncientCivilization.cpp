#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,l;
        cin>>n>>l;
        vector<int> v(n);
        for(int i=0; i<n; i++)
        cin>>v[i];
        int ans=0;
        for(int i=0; i<l; i++)
        {
            int cnt = 0;
            for(int j=0; j<n; j++)
            {
                if(v[j] & (1<<i))
                    cnt++;
            }
            if(cnt > n-cnt)
                ans += (1<<i);
        }
        cout<<ans<<endl;
    }
    return 0;
}