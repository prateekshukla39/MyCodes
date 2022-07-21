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
        for(int &i : v)
            cin>>i;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                sum += j - i + 1;
                for(int k = i; k<=j; k++)
                {
                    if(v[k]==0)
                        sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}