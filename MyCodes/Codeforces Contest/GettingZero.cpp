#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    for(int i=0; i<n; i++)
    {
        int x = v[i], cnt1, cnt2 = 0;
        int l = 0;
        while(true)
        {
            int j, k;
            j = pow(2,l);
            k = pow(2,l+1);
            if(x>j && x<=k)
            {
                cnt1 = k - x;
                break;
            }
            l++;
        }
        int z = v[i] + cnt1;
        while(z != 32768)
        {
            z *= 2;
            cnt2++;
        }
        v[i] = cnt1 + cnt2; 
    }
    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}