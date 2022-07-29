#include<bits/stdc++.h>

using namespace std;

void KClosestPointsToOrigin(vector<pair<int, int>> p, int k)
{  
    priority_queue<pair<int, pair<int, int>>> maxH;
    for(int i = 0; i < p.size(); i++)
    {
        int dist = (p[i].first)*(p[i].first) + (p[i].second)*(p[i].second);
        maxH.push({dist, p[i]});
        if(maxH.size() > k)
            maxH.pop();
    }
    // Print 
    while(maxH.size() > 0)
    {
        cout<<maxH.top().second.first<<" "<<maxH.top().second.second<<endl;
        maxH.pop();
    }
    return;
}

int main()
{
    vector<pair<int, int>> p = {{1, 3}, 
                                {-2, 2}, 
                                {5, 8}, 
                                {0, 1}};
    int k = 2;
    KClosestPointsToOrigin(p, k);
    return 0;
}