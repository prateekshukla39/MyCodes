#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int t;
    cin>>t;
    while(t--)
    {
    cin>>n;
    while(n>0)
    {
        int num, x;
        num = n%10;
        x = n - num;
        for(int i =  0; i<10; i++)
        {
            if(n%7==0)
            {
            cout<<n<<endl;
            n = 0;
            break;
            }
            if(((x+i)%7)==0)
            {
                cout<<x+i<<endl;
                n = 0;
                break;
            }  
        }
    }
    }
    return 0;
}