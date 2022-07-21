#include<bits/stdc++.h>

using namespace std;

pair<int, int> minPair(vector<int> a1, vector<int> a2)
{
    int n = a1.size(), m = a2.size();
    sort(a2.begin(), a2.end());

    pair<int, int> ans = {-1, -1};
    int diff = INT_MAX;

    for(int x : a1)
    {
        auto lb = lower_bound(a2.begin(), a2.end(), x) - a2.begin();
        if(lb >= 1 && x - a2[lb - 1] < diff)
        {
            diff = x - a2[lb - 1];
            ans.first = x;
            ans.second = a2[lb - 1];
        }
        if(lb != a2.size() && a2[lb] - x < diff)
        {
            diff = a2[lb - 1] - x;
            ans.first = a2[lb];
            ans.second = x;
        }
    }

    return ans;
}

int main()
{
    vector<int> a1 = {5,-1,10,20,3}, a2 = {26,134,135,15,17};
    pair<int, int> result = minPair(a1, a2);
    cout<<result.first<<","<<result.second<<endl;
    return 0;
}