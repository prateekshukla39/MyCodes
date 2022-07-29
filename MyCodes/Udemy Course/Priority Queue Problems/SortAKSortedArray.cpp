#include<bits/stdc++.h>

using namespace std;

void sortKSorted(vector<int> v, int k)
{
    priority_queue<int, vector<int>, greater<int>> minH;
    for (int i = 0; i < v.size(); i++)
    {
        minH.push(v[i]);
        if(minH.size() > k)
        {
            cout<<minH.top()<<" ";
            minH.pop();
        }
    }
    while(minH.size() > 0)
    {
        cout<<minH.top()<<" ";
        minH.pop();
    }
    cout<<endl;
    return;
}

int main()
{
    vector<int> v = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    sortKSorted(v, k);
    return 0;
}