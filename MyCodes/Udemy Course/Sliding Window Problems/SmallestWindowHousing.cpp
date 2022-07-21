#include<bits/stdc++.h>

using namespace std;

pair<int, int> sliding_window(vector<int> v, int sum)
{
    int i = 0, j = 0, current_sum = 0;
    map<int, pair<int, int>> ans;
    while(j < v.size())
    {
        current_sum += v[j];
        j++;

        while(i<j && current_sum > sum)
        {
            current_sum -= v[i];
            i++;
        }

        if(current_sum == sum)
            ans[j-1-i] = {i, j-1};
    }
    auto result = ans.begin();
    return (result->second);
}

int main()
{
    int sum = 8;
    vector<int> v = {1,3,2,1,4,1,3,2,1,1,2};
    auto i = sliding_window(v, sum);
    cout<<i.first<<"-"<<i.second<<endl;
    return 0;
}