#include<bits/stdc++.h>

using namespace std;

bool is_integer(float k)
{
  return floor(k) == k;
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int x, y;
        cin>>x>>y;
        if(x == 0 && y == 0)
            cout<<0<<endl;
        else if(is_integer(float(sqrt(x*x + y*y))))
            cout<<1<<endl;
        else
            cout<<2<<endl;
    }
    return 0;
}