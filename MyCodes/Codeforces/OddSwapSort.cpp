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
        vector<int> v(n);
        int maxO = 0, maxE = 0;
        bool f = false;
        for(int &i : v)
            cin>>i;
        for(int i = 0; i < n; i++)
        {
            if(v[i]&1){
                if(v[i]<maxO){
                    cout<<"No"<<endl;
                    f = true;
                    break;
                }
            }
            else {
                if(v[i]<maxE){
                    cout<<"No"<<endl;
                    f = true;
                    break;
                }
            }
            if(v[i]&1)
                maxO = max(maxO,v[i]);
            else
                maxE = max(maxE,v[i]);
        }
        if(!f)
            cout<<"Yes"<<endl;
    }
    return 0;
}