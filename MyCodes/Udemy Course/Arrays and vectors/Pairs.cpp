#include<bits/stdc++.h>

using namespace std;

vector<int> Pairs(vector<int> p, int sum)
{
    vector<int> result;
    unordered_set<int> s;
    for (int i = 0; i < p.size();i++)
    {
        int x = sum - p[i];
        if(s.find(x) != s.end())
        {
            result.push_back(x);
            result.push_back(p[i]);
            return result;
        }
        s.insert(p[i]);
    }
}

int main()
{
    vector<int> v = {10, 5,2,3,-6,9,11};
    int sum = 4;
    vector<int> result = Pairs(v,sum);
    for(auto i : result)
    {
        cout<<i<<endl;
    }
    return 0;
}