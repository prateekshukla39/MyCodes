#include<bits/stdc++.h>

using namespace std;

int binarySearch(vector<vector<int>> v, int l, int r, int t, int b, int k)
{
    int s = t;
    int e = b, id = -1;

    while(s <= e)
    {
        int m = (s + e) / 2;
        
        int num = v[m][r];
        if(num >= k)
        {
            id = m;
            e = m - 1;
        }
        else 
        {
            s = m + 1;
        }
    }
    return id;
}

pair<int,int> search(int m, int n, vector<vector<int>> v, int k)
{
    //write your code here.
    int l = 0, r = m - 1;
    int t = 0, b = n - 1;
    bool row = true;
    while(l <= r && t <= b)
    {
        if(row)
        {
            int indx = lower_bound(v[t].begin(), v[t].end(), k) - v[t].begin();
            if(v[t][indx] == k)
                return {t, indx};
            r = indx;
            row = false;
        }
        else
        {
            int indx = binarySearch(v, l, r, t, b, k);
            if(v[indx][r] == k)
                return {indx, r};

            t = indx;
            row = true;
        }
    }
    return {-1, -1};
}

int main()
{
    int m, n, k;
    cin>>n>>m>>k;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>v[i][j];
    auto p = search(m, n, v, k);
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}