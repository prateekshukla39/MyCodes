#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
        }
        int count = 0;
        vector<int> cond = v; 
        for(int i = 1; i < n-1; i++)
        {
            if(v[i]>v[i-1]&&v[i]>v[i+1])
            {
                if(v[i-1]!=cond[i])
                {
                    v[i-1] = v[i];
                }
                else{
                    v[i+1] = v[i];
                    count++;
                }
            }
        }
        cout<<count<<endl;
        for(auto i : v)
        cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}