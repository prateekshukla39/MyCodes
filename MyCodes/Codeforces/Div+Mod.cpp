#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int l, r, a;
        cin>>l>>r>>a;
        if((l/a)==(r/a))
            cout<<(r/a) + (r%a)<<endl;
        else
        {
            if(((r/a) + (r%a)) > (((r/a)-1) + (a-1)))
                cout<<(r/a) + (r%a)<<endl;
            else
                cout<<((r/a)-1) + (a-1)<<endl;
        }
    }
    return 0;
}