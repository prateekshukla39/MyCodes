#include<bits/stdc++.h>

using namespace std;

void KClosest(vector<int> v, int k, int num)
{
    priority_queue<pair<int, int>> maxH;
    for(int i = 0; i < v.size(); i++)
    {
        maxH.push({abs(v[i] - num), v[i]});
        if(maxH.size() > k)
            maxH.pop();
    }
    // Print
    while(maxH.size() > 0)
    {
        cout<<maxH.top().second<<" ";
        maxH.pop();
    }
    return;
}

int main()
{
    vector<int> v = {6, 10, 4, 3, 20, 15};
    int k = 3, num = 7;
    cout<<"K Closest Numbers : ";
    KClosest(v, k, num);
    return 0;
}