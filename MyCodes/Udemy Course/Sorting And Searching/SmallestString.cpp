#include<bits/stdc++.h>

using namespace std;

bool compare(string x, string y)
{
    return x + y < y + x;
}

int main()
{
    string s[] = {"a", "ab", "aba"};
    int n = 3;
    sort(s, s + n, compare);

    for(auto ch : s)
        cout<<ch;
    cout<<endl;

    return 0;
}