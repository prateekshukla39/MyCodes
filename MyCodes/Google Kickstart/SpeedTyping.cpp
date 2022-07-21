#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string I, P;
        cin>>I;
        cin>>P;
        if(P.length()<I.length())
            cout<<"IMPOSSIBLE!"<<endl;
        else{
            int diff = P.length() - I.length();
            bool flag = false;
            int cnt = 0, i = 0, j = 0;
            while(j<P.length())
            {
                if(I[i]==P[j])
                    i++, j++, cnt++;
                else
                    j++;
                if(cnt==I.length())
                {
                    flag = true;
                    break;
                }
            }
            if(!flag)
                cout<<"IMPOSSIBLE"<<endl;
            else
                cout<<diff<<endl;
        }
    }
    return 0;
}