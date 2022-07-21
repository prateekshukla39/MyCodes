#include <bits/stdc++.h>

using namespace std;

#define int      long long int

signed main() 
{
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        bool flag = true;
        int gcd = v[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            int x = v[i];
            if(x % gcd)
            {
                flag = false;
                break;
            }
            gcd = (gcd * x)/(__gcd(gcd, x));
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
	}
	return 0;
}
