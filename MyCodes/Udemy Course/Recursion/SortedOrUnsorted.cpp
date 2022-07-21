#include<bits/stdc++.h>

using namespace std;

string SortedOrUnsorted(vector<int> &arr, int index)
{
    int n = arr.size();
    // Base Case
    if(index >= n)
        return "Sorted";
    if(arr[index] < arr[index - 1])
        return "Unsorted"; 
    // Recursive Case
    return SortedOrUnsorted(arr, index + 1);
}

int main()
{
    vector<int> arr = {1,2,3,4,8,9,10};
    cout<<SortedOrUnsorted(arr, 1)<<endl;
    return 0;
}