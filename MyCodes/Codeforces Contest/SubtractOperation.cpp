#include<bits/stdc++.h>

using namespace std;

#define int        long long int

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int n, s;
      cin>>n>>s;
      vector<int> v(n);
      unordered_map<int, int> m;
      for(int &i : v)
      {
          cin>>i;
          m[i]++;
      }
      bool flag = false;
      for(int i : v)
      {
        if(m[i+s])
        {
          flag = true;
          break;
        }
      }
      if(flag)
        cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;
    }
    return 0;
}