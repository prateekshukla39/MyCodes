#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> v)
{
    map<int, int> m;
    int n = v.size(), result = -1;
    for (int i = 0; i < n; i++)
    {
        if(m.count(v[i]))
            result = max(result, m[v[i]]+n-i);
        m[v[i]] = i;
    }
    return result;    
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        cout<<solve(v)<<endl;
    }
    return 0;
}