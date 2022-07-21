#include<bits/stdc++.h>

using namespace std;

void Powerset(vector<int> arr, vector<int> output, int index)
{
    // Base Case
    if(index >= arr.size())
    {
        for(auto i : output)
            cout<<i<<" ";
        cout<<endl;
        return;
    }
    // Recursive case
    // Inclusion
    Powerset(arr, output, index + 1);
    // Exclusion
    output.push_back(arr[index]);
    Powerset(arr, output, index + 1);
}

int main()
{
    vector<int> arr = {1,2,3}, Result;
    Powerset(arr, Result, 0);
    return 0;
}