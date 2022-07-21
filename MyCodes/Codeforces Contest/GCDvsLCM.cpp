#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n&1)
        {
            if(n >=7)
            {
                int a = 2, b = n - 5, c = 1, d = 2;
                cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
            }
            else if(n = 5)
            {
                cout<<2<<" "<<1<<" "<<1<<" "<<1<<endl;
            }
        }
        else
        {
            if(n >= 8)
            {
                int a = 2, b = n - 6, c = 2, d = 2;
                cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
            }
            else if(n == 4)
                cout<<1<<" "<<1<<" "<<1<<" "<<1<<endl;
            else if(n == 6)
                cout<<3<<" "<<1<<" "<<1<<" "<<1<<endl;
        }

    }
    return 0;
}