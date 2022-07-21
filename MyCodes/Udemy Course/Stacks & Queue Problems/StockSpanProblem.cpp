#include<bits/stdc++.h>

using namespace std;

vector<int> stockSpan(vector<int> v) 
{   
    int n = v.size();
    vector<int> result;
    stack<int> stack;
    stack.push(0);
    result.push_back(1);
    for(int i = 1; i < n; i++)
    {
        int currentPrice = v[i];
        while(!stack.empty() && v[stack.top()] <= currentPrice)
            stack.pop();
        if(!stack.empty())
        {
            int previousHighest = stack.top();
            result.push_back(i - previousHighest);
        }
        else
            result.push_back(i + 1);
        stack.push(i);
    }
    return result;
}

int main()
{
    vector<int> v = {100, 80, 60, 70, 60, 75, 85};
    for(auto span : stockSpan(v))
        cout<<span<<" ";
    cout<<endl;
    return 0;
}