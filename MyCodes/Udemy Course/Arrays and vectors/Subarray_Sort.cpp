#include<bits/stdc++.h>

using namespace std;

bool OutOfOrder(vector<int> v, int i)
{
    int x = v[i], n = v.size();
    if(i==0)
    return x>v[1];
    if(i==n-1)
    return x<v[i-1];
    return (x>v[i+1] || x<v[i-1]);
}

pair<int, int> SubarraySort(vector<int> v)
{
    int n = v.size(), smallest = INT_MAX, largest = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        int x = v[i];
        if(OutOfOrder(v,i))
        {
            smallest = min(smallest,x);
            largest = max(largest,x);
        }
    }    
    if(smallest==INT_MAX)
    return {-1,-1};
    int left = 0, right = n - 1;
    while(smallest>v[left])
    {
        left++;
    }
    while(largest<v[right])
    {
        right--;
    }
    return {left,right};
}
int main()
{
    vector<int> v{1,2,3,4,5,8,6,7,9,10,11};
    auto p = SubarraySort(v);
    cout<<"["<<p.first<<","<<p.second<<"]"<<endl;
    return 0;
}