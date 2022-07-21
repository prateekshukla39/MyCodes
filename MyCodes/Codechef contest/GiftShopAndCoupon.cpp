#include <bits/stdc++.h>
using namespace std;
#define int      long long int

signed main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	  int n,k;
	  cin>>n>>k;
	  vector<int> v(n);
	  for(int i = 0; i<n; i++)
        cin>>v[i];
      sort(v.begin(), v.end());
      int sum = 0, items = 0;
      int i;
      for(i = 0; i<n; i++)
      {
          if(sum + (v[i]/2+(v[i]%2))>k)
            break;
          sum += v[i];
          items++;
      }
      cout<<items<<endl;
	}
	return 0;
}
