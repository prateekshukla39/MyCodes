#include<bits/stdc++.h>

using namespace std;

void subsets(string s, string o)
{
    // Base case
    if(s.length() == 0)
    {
        cout<<o<<endl;
        return;
    }
    // Recursive case
    string o1 = o;
    string o2 = o;
    o2.push_back(s[0]);
    s.erase(s.begin() + 0);
    subsets(s, o1);
    subsets(s, o2);
    return;
}

int main()
{
    string s = "abc", o = "";
    subsets(s, o);
    return 0;
}