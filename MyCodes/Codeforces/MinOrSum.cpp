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
        for (int i = 0; i < n; i++)
        cin >> v[i];
        for(int i = 0; i < n-1; i++)
        {
            int x, y;
            x=0;
            y=(v[i]|v[i+1]);
            v[i] = x;
            v[i+1] = y;
        }
        int sum = 0;
        for(auto i : v)
        sum += i;
        cout << sum << endl;
    }
    return 0;
}