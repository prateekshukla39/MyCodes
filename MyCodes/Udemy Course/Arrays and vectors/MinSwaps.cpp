#include<bits/stdc++.h>

using namespace std;

int MinSwaps(vector<int> v)
{
    int swaps = 0, n = v.size();
    pair<int, int> p[n];
    for(int i = 0; i < n; i++)
    {
        p[i].first = v[i];
        p[i].second = i;
    }
    sort(p, p+n);
    vector<bool> visited(n,false);
    for(int i = 0; i < n; i++)
    {
        if(visited[i]==true || p[i].second == i)
        {
            continue;
        }
        int node = i;
        int cycle = 0;
        while(!visited[node]) 
        {
            visited[node] = true;
            node = p[node].second;
            cycle++;
        }
        swaps += (cycle - 1);
    }
    return swaps;
}
int main()
{
    vector<int> v{5,4,3,2,1};
    cout<<MinSwaps(v)<<endl;
    return 0;
}