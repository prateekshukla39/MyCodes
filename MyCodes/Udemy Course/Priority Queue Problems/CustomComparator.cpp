#include<bits/stdc++.h>

using namespace std;

class Compare
{
    public:
    bool operator()(int a, int b)
    {
        return a > b; // reverse comparison to get decending output
    }
};

int main()
{
    vector<int> v = {12, 64, 3, 90, 10, 9};
    priority_queue<int, vector<int>, Compare> heap;
    for(auto i : v)
        heap.push(i);
    while(!heap.empty())
    {
        cout<<heap.top()<<" ";
        heap.pop();
    }
    cout<<endl;
    return 0;
}