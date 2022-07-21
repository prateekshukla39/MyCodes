#include<bits/stdc++.h>

using namespace std;

vector<int> maxInWindow(vector<int> input, int k)
{   
    int n = input.size();
    vector<int> result;
    multiset<int> set;
    int i, j;
    for(int i = 0; i < k; i++)
        set.insert(input[i]);
    auto it = set.rbegin();
    result.push_back(*it);
    
    i = 0, j = k;
    while(j < n)
    {
        set.insert(input[j]);
        set.erase(set.find(input[i]));
        auto it = set.rbegin();
        result.push_back(*it);
        i++;
        j++;
    }
    return result;
}

int main()
{
    int k = 3;
    vector<int> input = {1,2,3,1,4,5,2,3,6}, result;
    result = maxInWindow(input, k);
    for(auto i : result)
        cout<<i<<",";
    cout<<endl;
    return 0;
}