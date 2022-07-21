#include <bits/stdc++.h>

using namespace std;

#define int      long long int

signed main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
        int ans = 0, cnt = 0;
        for(int i : s)
        {
            if(i == '0')
                cnt++;
        }
        int i = 0;
        while(cnt<n)
        {
            if((i<n-1)&&(s[i] == '1' && s[i+1] == '1'))
            {
                cnt++;
                s[i] = '0';
                i += 2;
            }
            else if(s[i] == '1')
            {
                cnt++;
                s[i] = '0';
                i++;
            }
            else
                i++;
            if(i == n || cnt == n)
            {
                ans++;
                i = 0;
            }
        }
        cout<<ans<<endl;
	}
	return 0;
}
