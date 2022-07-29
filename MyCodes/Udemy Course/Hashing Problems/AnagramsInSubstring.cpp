#include<bits/stdc++.h>

using namespace std;

vector<int> hashing(string s, int i, int j)
{
    vector<int> freq(26, 0);
    for(int k = i; k <= j; ++k)
    {
        char ch = s[k];
        freq[ch - 'a']++;
    }
    return freq;
}

int anagramsInSubStrings(string s)
{
    map<vector<int>, int> m;
    for(int i = 0; i < s.size(); ++i)
        for(int j = i; j < s.size(); ++j)
        {
            vector<int> h = hashing(s, i, j);
            m[h]++;
        }
    
    int ans = 0;
    for(auto i : m)
    {
        int freq = i.second;
        if(freq >= 2)
            ans += freq*(freq - 1)/2; // ans += freq C 2 (combinations)
    }
    return ans;
}

int main()
{
    string s = "abba";
    cout<<anagramsInSubStrings(s)<<endl;
    return 0;
}