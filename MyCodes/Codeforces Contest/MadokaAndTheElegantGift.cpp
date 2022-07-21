#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
        cin>>n>>m;
        vector<string> v(n);
        for(int i = 0; i < n; i++)
        {
            cin>>v[i];
        }
        for(int i = 0; i < n - 1; i++)
        {
            int j = 0;
            while(j<m-1)
            {
                int s1, s2, s3, s4;
                s1 = v[i][j] - 48;
                s2 = v[i][j+1] - 48;
                s3 = v[i+1][j] - 48;
                s4 = v[i+1][j+1] - 48;
                if(s1+s2+s3+s4==3)
                {
                    cout<<"NO"<<endl;
                    return;
                }
                j++;
            }
        }
        cout<<"YES"<<endl;
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}