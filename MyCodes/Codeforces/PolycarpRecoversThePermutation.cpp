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
            cin>>v[i];
        if(n==1 || n==2)
        {
            for(int i = 0; i < n; i++)
                cout<<v[i]<<" ";
            cout<<endl;
        }
        else if(v[n-1]==n)
        {
            for(int i = n - 2; i > 0; i--)
                cout<<v[i]<<" ";
            cout<<v[0]<<" "<<n<<endl;
        }
        else if(v[0]==n)
        {
            cout<<n<<" "<<v[n-1]<<" ";
            for(int i = n - 2; i > 0; i--)
                cout<<v[i]<<" ";
            cout<<endl;
        }
        else
            cout<<-1<<endl;
    }
    return 0;
}