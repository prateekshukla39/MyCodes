#include<bits/stdc++.h>

using namespace std;

int MaxSubarraySum(vector<int> v)
{
    int count = 0, Max = INT_MIN, sum = 0;
    for(int i : v)
    {
        if(i<0)
            count++;
    }
    if(count == v.size())
        return 0;
    for(int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        Max = max(Max, sum);
        if(sum<0)
            sum = 0;
    }
    return Max;
}

int main()
{
    vector<int> v{-1,2,3,4,-2,6,-8,3};
    cout<<MaxSubarraySum(v)<<endl;
    return 0;
}