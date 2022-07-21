#include<bits/stdc++.h>

using namespace std;

void Subsequences(string s, string o, vector<string> &v)
{
    //Base Case:
    if(s.length() == 0)
    {
        v.push_back(o);
        return;
    }
    // Recursive Case:
    char ch = s[0];
    string reducedInput = s.substr(1);
    Subsequences(reducedInput, o + ch, v);
    Subsequences(reducedInput, o, v);
}
bool compare(string s1, string s2)
{
    if(s1.length() == s2.length())
        return s1 < s2;
    return s1.length() < s2.length();
}
int main()
{
    string s;
    cin>>s;
    vector<string> v;
    string output = "";
    Subsequences(s, output, v);

    sort(v.begin(), v.end(), compare);

    for(auto ch : v)
        cout<<ch<<",";
    cout<<endl;

    return 0;
}