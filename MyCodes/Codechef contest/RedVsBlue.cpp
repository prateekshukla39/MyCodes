#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, r, b;
        cin >> n >> r >> b;
        int rr = r / (b + 1);
        int rem = r % (b + 1),c = 0;
        while(b--)
        {
            int red = rr;
            while(red--)cout << 'R',c++;
            if(rem)cout << 'R',rem--,c++;
            cout << 'B';
        }
        rem = r - c;
        while(rem--)cout << 'R';
    }
    return 0;
}