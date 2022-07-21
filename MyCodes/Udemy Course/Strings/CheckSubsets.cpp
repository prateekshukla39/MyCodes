#include<bits/stdc++.h>

using namespace std;

string checkSubset(string s1, string s2)
{
    int i = 0, j = 0, cnt = 0;
    while(i < s2.length() && j < s1.length())
    {
        if(s1[j] == s2[i])
            cnt++, i++, j++;
        else
            j++;
    }
    if(cnt == s2.length())
        return "YES";
    else
        return "NO";
}

int main()
{
    string s1 = "codingminutes", s2 = "cines";
    cout<<checkSubset(s1, s2)<<endl;
    return 0;
}