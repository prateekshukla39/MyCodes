#include<bits/stdc++.h>

using namespace std;

int longestSubarrayKSum(vector<int> arr, int k)
{
    //Complete this function and return the length of longest subarray
    unordered_map<int, int> m;
    int prefix_sum = 0;
    int length = INT_MIN;
    for(int i = 0; i < arr.size(); i++)
    {
        prefix_sum += arr[i];
        // Special Check for Prefix Sum problems
        if(prefix_sum - k == 0)
            length = max(length, i + 1);
        if(m.find(prefix_sum - k) != m.end())
            length = max(length, i - m[prefix_sum - k]);
        else
            m[prefix_sum] = i;
    }
    return length;
}

int main()
{
    vector<int> arr = {0, -2, 1, 2, 3, 4, 5, 15, 10, 5};
    int k = 15;
    cout<<longestSubarrayKSum(arr, k)<<endl;
    return 0;
}