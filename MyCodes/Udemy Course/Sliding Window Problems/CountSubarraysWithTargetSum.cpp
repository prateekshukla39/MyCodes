#include<bits/stdc++.h>

using namespace std;

int cntSubarrays(vector<int> arr,int k)
{
    //complete this method
    int n = arr.size(), sum = 0, count = 0;
    unordered_map<int, int> prefix_sum;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum == k)
            count++;
        if(prefix_sum.find(sum - k) != prefix_sum.end())
            count += prefix_sum[sum - k];
        prefix_sum[sum]++;
    }
    return count;
}

int main()
{
    int k = -10;
    vector<int> arr = {10,2,-2,-20,10};
    cout<<cntSubarrays(arr,k)<<endl;
    return 0;
}