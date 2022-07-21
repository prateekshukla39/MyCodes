#include<bits/stdc++.h>

using namespace std;

double Square_root(int n, int p)
{
    int s = 0;
    int e = n;

    double ans = 0;
    while(s <= e)
    {
        int mid = (s + e) / 2;
        if(mid*mid == n)
            return mid;
        else if(mid*mid < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }

    double inc = 0.1;

    for(int place = 1; place <= p; place++)
    {
        while(ans*ans < n)
        {
            ans += inc;
        }
        ans = ans - inc;
        inc = inc/10.0;
    }

    return ans;
}

int main()
{
    int N, P;
    cin>>N>>P;
    cout<<Square_root(N, P)<<endl;
    return 0;
}