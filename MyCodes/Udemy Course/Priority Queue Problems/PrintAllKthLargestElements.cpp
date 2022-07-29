#include<bits/stdc++.h>

using namespace std;

// Time complexiety O(nlog(k))
void KthLargestPrint(vector<int> v, int k)
{
    priority_queue<int, vector<int>, greater<int>> minH;
    for (int i = 0; i < v.size(); i++)
    {
        minH.push(v[i]);
        if (minH.size() > k)
            minH.pop();
    }
    // Printing
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
    vector<int> v = {6, 10, 4, 3, 20, 15};
    int k = 3;
    KthLargestPrint(v, k);
    return 0;
}