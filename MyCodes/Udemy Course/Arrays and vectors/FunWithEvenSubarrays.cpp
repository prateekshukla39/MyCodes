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
        vector<int> v(n);
        for(int i=0; i<n; i++)
            cin>>v[i]; 
        int  i = n - 1, c = 0, steps =0, x = v[n-1];
        while(i>=0)
        {
            while(v[i]==x && i>=0)
            {
                c++, i--;
            }
            if(i<0)
                break;
            steps++;
            i -= c;
            c *= 2;
        }
        cout<<steps<<endl;
    }
    return 0;
}