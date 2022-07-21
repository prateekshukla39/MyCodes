#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string x;
        cin>>x;
        bool flag = false;
        for(int i = x.size()-1; i >= 1; i--)
        {
            int y = x[i]+x[i-1] - 96;
            if(y>=10)
            {
                flag = true;
                for(int j = 0; j < x.size(); j++)
                {
                    if(j==i-1)
                    {
                        cout<<y;
                        j++;
                    }
                    else
                    cout<<x[j];
                }
                cout<<endl;
                break;
            }    
        }  
        if(!flag)
        {
            cout<<x[0]+x[1] - 96;
            for(int j = 2; j < x.size(); j++)
            cout<<x[j];
            cout<<endl;
        }
    }
    return 0;
}