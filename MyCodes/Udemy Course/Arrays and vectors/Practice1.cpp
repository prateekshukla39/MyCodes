#include<bits/stdc++.h>

using namespace std;

int main()
{
    int l,r,k,t;
    cin>>t;
    while(t--)
    {
        cin>>l>>r>>k;
        int x = ((r-l)/2)+1;
        if(r%2==0 && l%2==0)
        x--;
        if(x<=k || (l==r && l!=1))
        cout<<"yes";
        else
        cout<<"no";
        cout<<endl;
    }
    return 0;
}