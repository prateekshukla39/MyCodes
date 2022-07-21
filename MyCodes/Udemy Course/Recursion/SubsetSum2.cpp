#include<bits/stdc++.h>

using namespace std;

int SubsetSum(vector<int> &v, int target, int indx)
{
    int n = v.size();
    // Base case
    if(indx == n)
    {
        if(target == 0)
            return 1;
        else
            return 0;
    }

    // Recursive case
    return SubsetSum(v, target - v[indx], indx + 1) + SubsetSum(v, target, indx + 1);
}

int main()
{
    vector<int> v = {1,2,3,4,5};
    int target = 6;
    cout<<SubsetSum(v, target, 0)<<endl;
    return 0;
}