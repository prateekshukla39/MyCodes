#include <bits/stdc++.h>
using namespace std;
#define int      long long int

bool discountCheck(int v, int amt)
{
    return amt>=(v/2) + (v%2);
}

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
      int sum = v[0], items = 0;
      if(v[0]/2>k)
      {
        cout<<0<<endl;
        exit(0);
      }
      int i;
      for(i = 0; i<n; i++)
      {
          if(sum==k)
          {
              cout<<i+1<<endl;
              exit(0);
          }
          if(sum>k)
             break;
          items++;
          sum += v[i];
      }
      if((sum>k)&&(discountCheck(v[i+1],sum - k)))
        items++;
      cout<<items<<endl;
	}
	return 0;
}
