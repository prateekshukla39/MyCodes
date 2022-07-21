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
        for (int i = 0; i < n; i++)
            cin>>v[i];
        int i = 0, j = n - 1;
        while(j>=0 && v[j])
            j--;
        while(i<n && v[i])
            i++;
        if(j<0)
            cout<<0<<endl;
        else
            cout<<j - i + 2<<endl;
    }
    return 0;
}