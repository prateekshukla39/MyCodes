#include<bits/stdc++.h>

using namespace std;

// O(nlog(k)) time complexity
int KthSmallestElement(vector<int> v, int k)
{
    priority_queue<int> maxH;

    for(int i = 0; i < v.size(); i++)
    {
        maxH.push(v[i]);
        if(maxH.size() > k)
            maxH.pop();
    }
    return maxH.top();
}

int main()
{
    vector<int> v = {6, 10, 4, 3, 20, 15};
    int k = 3;
    cout<<"Kth smallest element is "<<KthSmallestElement(v, k)<<endl;
    return 0;
}