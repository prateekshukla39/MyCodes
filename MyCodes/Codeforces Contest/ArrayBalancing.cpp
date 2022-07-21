#include<bits/stdc++.h>

using namespace std;

#define int     long long int

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++)
            cin>>a[i];
        for(int i = 0; i < n; i++)
            cin>>b[i];
        for(int i = 1; i < n; i++)
        {
            if(abs(a[i-1] - b[i]) < abs(a[i-1] - a[i]))
                swap(a[i], b[i]);
        }
        int suma = 0, sumb = 0;

        for(int i = 0; i < n - 1; i++)
        {
            suma += abs(a[i] - a[i+1]);
            sumb += abs(b[i] - b[i+1]);
        }
        cout<<suma + sumb<<endl;
    }
    return 0;
}