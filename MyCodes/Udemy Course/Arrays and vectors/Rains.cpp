#include<bits/stdc++.h>

using namespace std;

int Rains(vector<int> v)
{
    int n = v.size();
    vector<int> left(n), right(n);
    if(n<=2)
    return 0;
    left[0] = v[0];
    right[n-1] = v[n-1];
    for(int i=1; i<n; i++)
    {
        left[i] = max(left[i-1],v[i]);
        right[n-1-i] = max(right[n-i],v[n-1-i]);
    }
    int water = 0;
    for(int i=0; i<n; i++)
    {
        water += (min(left[i],right[i]) - v[i]);
    }
    return water;
}
int main()
{
    vector<int> v{0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<Rains(v)<<endl;
    return 0;
}