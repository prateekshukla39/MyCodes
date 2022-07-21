#include<bits/stdc++.h>

using namespace std;

int subsets(string str, string output[])
{
    // Base Case
    if(str.length() == 0)
    {
        output[0] = "";
        return 1;
    }
    // Recursive Case
    int smaller_size = subsets(str.substr(1), output);
    for(int i = 0; i < smaller_size; i++)
        output[i + smaller_size] = str[0] + output[i];
    return 2*smaller_size;
}

int main()
{
    string str, output[1000];
    cin>>str;
    int n = subsets(str, output);
    for(int i = 0; i < n; i++)
        cout<<output[i]<<" ";
    cout<<endl;
    return 0;
}