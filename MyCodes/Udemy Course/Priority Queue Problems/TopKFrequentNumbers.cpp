#include<bits/stdc++.h>

using namespace std;

void topKFrequentNumbers(vector<int> v, int k)
{
    unordered_map<int, int> m;
    for(int i = 0; i < v.size(); i++)
        m[v[i]]++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
    for(auto it : m)
    {
        minH.push({it.second, it.first});
        if(minH.size() > k)
            minH.pop();
    }
    // Print
    while(minH.size() > 0)
    {
        cout<<minH.top().second<<" ";
        minH.pop();
    }
    cout<<endl;
    return;
}

int main()
{
    vector<int> v = {1, 1, 1, 3, 3, 2, 4};
    int k = 2;
    topKFrequentNumbers(v, k);
    return 0;
}