#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    x: while (t--)
    {
        int n, k;
        cin >> n >> k;
        int count = 0;
        if(k>((n/2)+(n%2)))
        {
            cout<<-1<<endl;
            goto x;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if((count<k)&&(i == j && !(i&1)))
                {
                    cout<<"R";
                    count++;
                }
                else
                    cout<<".";
            }
            cout<<endl;
        }
    }
    return 0;
}