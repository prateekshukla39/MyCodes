#include<bits/stdc++.h>

using namespace std;

vector<int> productArray(vector<int> arr)
{
    vector<int> result(arr.size());
    int product = 1;
    for(int i : arr)
        product *= i;
    for(int i = 0; i < arr.size(); i++)
    {
        
    }
}

int main()
{
    vector<int> arr{1,2,3,4,5};
    auto result = productArray(arr);
    for(auto i : result)
    cout<<i<<endl;
    return 0;
}