#include<bits/stdc++.h>

using namespace std;

bool isPossible(int mid, vector<int>& v, int k)
{
    int n = v.size();
    int partitions = 0, current_coins = 0;
    for (int i = 0; i < n; i++)
    {
        if(current_coins + v[i] >= mid)
        {
            partitions++;
            current_coins = 0;
        }
        else
            current_coins += v[i];
    }
    return partitions >= k;
}

int getCoins(vector<int> arr, int k)
{
    //return the max coins that you can win!
    int s = 0;
    int e = 0;
    for(int i : arr)
        e += i;
    int ans = -1;
    while(s <= e)
    {
        int mid = (s + e) / 2;
        bool isPoss = isPossible(mid, arr, k);
        if(isPoss)
        {
            s = mid + 1;
            ans = mid;
        }
        else
            e = mid - 1;
    }
    return ans;
}

int main()
{
    int  k = 3;
    vector<int> v = {1,2,3,4};
    cout << getCoins(v, k);
    return 0;
}