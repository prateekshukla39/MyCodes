#include<bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> strs)
{
    //Write your code here. Do not modify the function or the parameters.
    vector<vector<string>> result; 
    unordered_map<string, vector<string>> mapAnagram;
    for(auto i : strs)
    {
        string s = i;
        sort(s.begin(), s.end());
        mapAnagram[s].push_back(i);
    }

    for(auto i : mapAnagram)
    {
        vector<string> st = i.second;
        sort(st.begin(), st.end());
        result.push_back(st);
    }

    return result;
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    for(auto i : groupAnagrams(strs))
    {
        for(auto s : i)
            cout<<s<<" ";
        cout<<endl;
    }
    return 0;  
}