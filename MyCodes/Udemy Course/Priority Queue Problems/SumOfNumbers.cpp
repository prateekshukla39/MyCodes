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
// Function to compute the sum between ath and bth smallest numbers
int sumOfNumbers(vector<int> v, int a, int b)
{
    int sum = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] > KthSmallestElement(v, a) && v[i] < KthSmallestElement(v, b))
            sum += v[i];
    }
    return sum; 
}

int main()
{
    vector<int> v = {1, 3, 5, 11, 12, 15};
    cout<<sumOfNumbers(v, 3, 6)<<endl;
    return 0;
}