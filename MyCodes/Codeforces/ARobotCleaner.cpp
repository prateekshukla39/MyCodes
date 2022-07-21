#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m, rb, cb, rd, cd;
        cin>>n>>m>>rb>>cb>>rd>>cd;
        int i = rb, j = cb, time = 0;
        bool flagi = false, flagj = false;
        while(true)
        {
            if(i==rd || j==cd)
                break;
            time++;
            if(i == n)
                flagi = true;
            if(j == m)
                flagj = true;
            if(flagi && flagj)
                i--,j--;
            else if(flagi && !flagj)
                i--,j++;
            else if(!flagi && flagj)
                i++,j--;
            else
                i++,j++;
        }
        cout<<time<<endl;
    }
    return 0;
}