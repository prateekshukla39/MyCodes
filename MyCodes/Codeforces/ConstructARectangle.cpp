#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> v(3);
        for(int i = 0; i < 3; i++)
            cin>>v[i];
        sort(v.begin(), v.end());
        if(v[0]==v[1] && v[2]%2==0)
            cout<<"YES";
        else if(v[1]==v[2] && v[0]%2==0)
            cout<<"YES";
        else if(v[0]+v[1]==v[2])
            cout<<"YES";
        else
            cout<<"NO";
        cout<<endl;
    }
    return 0;
}