#include<bits/stdc++.h>

using namespace std;

void solve() 
{
    long long int dc, dm, k, a, w;
    long long int hc, hm;
    cin>>hc>>dc>>hm>>dm>>k>>w>>a;
    for(int i = 0; i<=k; i++)
    {
        long long int CL, CA;
        CL = (hc + i*a);
        CA = ((k-i)*w + dc);
        long long int timeToKillMonster, timeToKillCharacter;
        timeToKillMonster = hm/CA;
        if(hm%CA)
            timeToKillMonster++;
        timeToKillCharacter = CL/dm;
        if(CL%dm)
            timeToKillCharacter++;
        if(timeToKillMonster<=timeToKillCharacter)
        {
            cout<<"YES";
            return;
        }
    }
    cout<<"NO";
    return;
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        solve();
        cout<<endl;
    }
    return 0;
}