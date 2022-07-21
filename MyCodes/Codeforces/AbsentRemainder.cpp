#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
        {
            cin>> v[i];
        }
        int min = v[0];
        for(int i = 0; i < n; i++)
        {
            if(min>v[i])
            min = v[i];
        }
        for(int i = 0, k = 0; k < n/2; i++)
        {
            if(v[i]!=min)
            {
            cout<<v[i]<<" "<<min<<endl;
            k++;
            }
        }
    }
    return 0;
}