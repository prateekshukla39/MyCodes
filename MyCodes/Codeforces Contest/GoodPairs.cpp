#include<bits/stdc++.h>

using namespace std;

#define int     long long int

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        int largest = INT_MIN, smallest = INT_MAX;
        for(int i=0; i<n; i++)
        {
            cin>>v[i];
            largest = max(largest,v[i]);
            smallest = min(smallest,v[i]);
        }
        int j, k;
        for(int i=0; i<n; i++)
        {
            if(smallest == v[i])
                j = i;
            if(largest == v[i])
                k = i;
        }
        cout<<++j<<" "<<++k<<endl;
    }
    return 0;
}