#include<bits/stdc++.h>

using namespace std;

#define int    long long int

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        int cntOdd = 0, cntEven = 0, ans = 0;
        for(int &i : v)
        {
            cin>>i;
            if(n%2 == 0)
                cntEven++;
            else
                cntOdd++;
        }
        if(cntOdd % 2 != 0)
        {
            if(cntOdd > cntEven)
                ans = cntEven;
            else
            {
                if(cntEven % 2 == 0)
                {
                    int CntEven = cntEven;
                    while(cntOdd < cntEven)
                    {
                        ans++;
                        CntEven /= 2;
                    }
                    ans += CntEven;
                }
                else
                {
                    int CntEven = cntEven - 1;
                    while(cntOdd <= cntEven)
                    {
                        ans++;
                        CntEven /= 2;
                    }
                    ans += CntEven + 1;
                }
            }
        }
        else if(cntOdd % 2 == 0)
        {
            if(cntOdd > cntEven)
            {
                if(cntOdd/2 > cntEven)
                    ans = cntEven;
                else
                {
                    while(cntOdd>0)
                    {
                        ans++;
                        cntOdd /= 2;
                    }
                }
            }
            else
            {
                while(cntOdd>0)
                {
                    ans++;
                    cntOdd /= 2;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}