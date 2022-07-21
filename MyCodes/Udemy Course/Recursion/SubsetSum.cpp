#include<bits/stdc++.h>

using namespace std;

int SubsetSum(vector<int> &v, int target, int idx)
{
    // Base Case
    if(idx == v.size())
    {
        if(target == 0)
            return 1;
        else
            return 0;
    }
    // Recursive Case
    int include = SubsetSum(v, target - v[idx], idx + 1);
    int exclude = SubsetSum(v, target, idx + 1);

    return include + exclude;
}

int main()
{
    vector<int> v = {1,2,3,4,5};
    int target = 6;
    int index = 0;
    cout<<SubsetSum(v, target, index)<<endl;
    return 0;
}