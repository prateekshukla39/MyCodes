#include<bits/stdc++.h>

using namespace std;

#define int     long long int

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin>>n>>s;
        n = n*n;
        cout<<s/n<<endl;
    }
    return 0;
}