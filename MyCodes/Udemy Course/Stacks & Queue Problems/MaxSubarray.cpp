#include<bits/stdc++.h>

using namespace std;

void maxSubarray(vector<int> a, int k)
{
    int n = a.size();
    deque<int> Q(k);
    // For the first k elements
    for (int i = 0; i < k; i++)
    {
        while(!Q.empty() && a[i] >= a[Q.back()])
            Q.pop_back();
        Q.push_back(i); 
    }
    // For remaining array
    for(int i = k; i < n; i++)
    {
        cout<<a[Q.front()]<<" ";
        // Removes elements from the left(contraction of out of bound elements or out of window elements from the left)
        while(!Q.empty() && Q.front() <= i - k)
            Q.pop_front();
        while(!Q.empty() && a[i] >= a[Q.back()])
            Q.pop_back();

        Q.push_back(i);   
    }
}

int main()
{
    vector<int> a = {1,2,3,1,4,5,2,3,5};
    int k = 3;
    maxSubarray(a, k);
    cout<<endl;
    return 0;
}