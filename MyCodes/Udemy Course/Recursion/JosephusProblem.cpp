#include<bits/stdc++.h>

using namespace std;

void solve(vector<int> v, int k, int index)
{
    // Base Case
    if(v.size() == 1)
    {
        cout<<v[0]<<endl;
        return;
    }
    // Recursive Case
    index = (index + k)%v.size();
    v.erase(v.begin() + index);
    solve(v, k, index);
}

int main()
{
    int n = 40, k = 7;
    vector<int> v;
    for(int i = 1; i <= n; i++)
        v.push_back(i);
    k--;
    int index = 0;

    solve(v, k, index);
    
    return 0;
}