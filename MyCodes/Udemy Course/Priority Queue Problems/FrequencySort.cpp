#include<bits/stdc++.h>

using namespace std;

void frequencySort(vector<int> v)
{
    unordered_map<int, int> m;
    for(int i = 0; i < v.size(); i++)
        m[v[i]]++;
    priority_queue<pair<int, int>> maxH;
    for(auto it : m)
        maxH.push({it.second, it.first});
    // Print
    while(maxH.size() > 0)
    {
        for(int i = 0; i < maxH.top().first; i++)
            cout<<maxH.top().second<<" ";
        maxH.pop();
    }
    cout<<endl;
    return;
}

int main()
{
    vector<int> v = {1, 1, 1, 3, 2, 2, 4};
    frequencySort(v);
    return 0;
}