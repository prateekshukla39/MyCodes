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
        vector<int> v(n), f(n+1,0);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
            while(v[i]>n)
                v[i] /= 2;
            f[v[i]]++;
        }
        bool flag = true;
        for(int i = n; i > 0; i--)
        {
            if(f[i]==0)
            {
                flag = false;
                break;
            }
            f[i/2] += f[i] - 1;
        }     
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;   
    }
    return 0;
}