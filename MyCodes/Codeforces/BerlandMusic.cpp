#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for(auto &i : v)
        cin >> i;
        string s;
        cin>>s;
        vector<int> comparisonsZ, comparisonsO;
        for(int i = 0; i < n; i++)
        {
            if(s[i]=='0')
            {
            comparisonsZ.push_back(v[i]);
            }
            else
            comparisonsO.push_back(v[i]);
        }
        int countz = comparisonsZ.size();
        sort(comparisonsZ.begin(), comparisonsZ.end());
        sort(comparisonsO.begin(), comparisonsO.end());
        unordered_map<int, int> m;
        for(int i = 0; i < countz; i++)
        {
            m[comparisonsZ[i]] = i + 1;
            //cout<<comparisonsZ[i]<<" ";
        }
        for(int i = countz; i < n; i++)
        {
            m[comparisonsO[i-countz]] = i + 1;
            //cout<<comparisonsO[i]<<" ";
        }
        for(int i = 0; i < n; i++)
        {
            cout<<m[v[i]]<<" ";
        }
        cout<<endl;
    }
    return 0;
}