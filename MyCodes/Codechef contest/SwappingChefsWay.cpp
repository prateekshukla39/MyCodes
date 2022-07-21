#include <bits/stdc++.h>
using namespace std;
#define int      long long int

signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
	  int n;
	  cin>>n;
	  string s, s2;
	  cin>>s;
	  bool flag = false;
	  s2 = s;
	  for(int i = 0; i<s.length()/2; i++)
	  {
	      if(s[i]>s[n-1-i])
	        swap(s[i],s[n-1-i]);
	  }
	  sort(s2.begin(), s2.end());
	  for(int i = 0; i<s.length(); i++)
	  {
	      if(s[i]!=s2[i])
	      {
	        flag = true;
	        break;
	      }
	  }
	  if(flag)
	    cout<<"NO";
	  else
	    cout<<"YES";
	  cout<<endl;
	}
	return 0;
}