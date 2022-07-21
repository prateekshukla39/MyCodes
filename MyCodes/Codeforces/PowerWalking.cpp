#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            m[x]++;
        }
        vector<int> ans;
        for(int i=1;i<=n;i++)
        {
            if(i<=m.size())
                ans.push_back(m.size());
            else{
                int x = i;
                ans.push_back(x++);
            }
        }
        for(auto it : ans)
        cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}