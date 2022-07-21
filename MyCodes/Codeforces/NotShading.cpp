#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,r,c;
        cin>>n>>m>>r>>c;
        set<int> row, column;
        r--, c--;
        bool flag = false;
        for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            char x;
            cin>>x;
            if(x=='B')
            {
                row.insert(i);
                column.insert(j);
                if(i==r && j==c)
                flag = true;
            }
        }
        if(flag)
            cout<<0<<endl;
        else if(row.empty() && column.empty())
            cout<<-1<<endl;
        else if(row.find(r)!=row.end() || column.find(c)!=column.end())
            cout<<1<<endl;
        else
            cout<<2<<endl;
    }
    return 0;
}