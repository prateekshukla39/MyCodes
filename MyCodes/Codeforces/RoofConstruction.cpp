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
        int max = n - 1, j = 0, min = n - 2;
        if(n == 1)
        {
            cout<<0<<endl;
            return 0;
        }
        while(true)
        {
            int x, y;
            x = pow(2,j);
            y = pow(2,j+1);
            if(max>=x && max<y)
            {
            min = x;
            break;
            }
            j++;
        }
        for(int i=min-1; i>=0; i--)
        {
            cout<<i<<" ";
        }
        for(int i=min; i<n; i++)
        {
            cout<<i<<" ";
        }
        
        cout<<endl;
    }
    return 0;
}