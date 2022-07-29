#include<bits/stdc++.h>

using namespace std;

int minCost(vector<int> v, int k)
{
    priority_queue<int, vector<int>, greater<int>> minH;
    for(int i = 0; i < v.size(); i++)
        minH.push(v[i]);
    int cost = 0;
    while(minH.size() > 1)
    {
        int first = minH.top();
        minH.pop();
        int second = minH.top();
        minH.pop();
        cost += (first + second);
        minH.push(first + second);
    }
    return cost;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int k = 2;
    cout<<minCost(v, k)<<endl;
    return 0;
}