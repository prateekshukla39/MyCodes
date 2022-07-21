#include<bits/stdc++.h>

using namespace std;

void permute(string str, vector<string> &result, int index)
{
    // Base Case
    if(index >= str.size())
    {
        result.push_back(str);
        return;
    }
    // Recursive Case
    for(int i = index; i < str.length(); i++)
    {
        swap(str[i], str[index]);
        permute(str, result, index + 1);
        swap(str[index], str[i]);
    }
}

int main()
{
    string str;
    cin>>str;
    vector<string> result;
    int index = 0;
    permute(str, result, index);
    for(auto st : result)
        cout<<st<<endl;
    return 0;
}