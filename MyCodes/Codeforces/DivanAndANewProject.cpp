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
        vector<pair<int, int> > v(n), v1, v2;
        for(int i = 0; i < n; i++)
        {
            cin >> v[i].first;
            v[i].second = i + 1;
        }
        sort(v.begin(), v.end(),greater<pair<int, int> >());
        for(int i = 0, j = 0, k = 0; i < n; i++)
        {
            if(i%2==0)
            {
                v1[j].first = v[i].first;
                v1[j].second = v[i].second;
                j++;
            }
            else
            {
                v1[k].first = v[i].first;
                v1[k].second = v[i].second;
                k++;
            }
        }
        int minTime = 0;
        for(int i = 0; i < v1.size(); i++)
            minTime += (v1[i].first)*(2*(i+1));
        for(int i = 0; i < v2.size(); i++)
            minTime += (v2[i].first)*(2*(i+1));
        cout<<minTime<<endl;
        for(int i = v2.size()-1; i >= 0; i--)
            cout<<v2[i].second<<" ";
        cout<<0<<" ";
        for(int i = 0; i < v1.size(); i++)
            cout<<v1[i].second<<" ";
        cout<<endl;
    }
    return 0;
}