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
        for (int i = 1; i <= n; i++)
        {
            int x;
            if(i == n)
            x = n - 1;
            else
            x = n;
            cout<<i<<" ";
            for (int j = 0; j < n-1; j++)
            {
                if(i!=n)
                {               
                    if(x > i)
                    {
                        cout<<x<<" ";
                        x--;
                    }
                    else{
                        cout<<x-1<<" ";
                        x--;
                    }
                }
                else
                cout<<x--<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}