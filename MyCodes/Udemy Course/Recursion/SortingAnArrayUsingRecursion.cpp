#include<bits/stdc++.h>

using namespace std;

void insert(vector<int> &v, int temp) 
{
    int n = v.size();
    // Base case
    if(n == 0 || v[n - 1] <= temp)
    {
        v.push_back(temp);
        return;
    }
    // Recursive case
    int temp2 = v[n - 1];
    v.pop_back();
    insert(v, temp);
    v.push_back(temp2);
}

void sort(vector<int> &v)
{
    int n = v.size();
    // Base case
    if(n == 0)
        return;
    // Recursive case
    int temp = v[n - 1];
    v.pop_back();
    sort(v);
    insert(v, temp);
}

int main()
{
    vector<int> v = {1,3,2,4,6,9};
    sort(v);
    for(auto i : v)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}