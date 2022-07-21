#include<bits/stdc++.h>

using namespace std;

void Required_Indices(vector<int> v,int sum)
{
    unordered_map<int, int> m;
    int current_sum = 0, c = 0;
    for(int i=0; i<v.size(); i++)
    {
        current_sum += v[i];
        
        if(current_sum == sum)
            cout<<0<<" - "<<i<<endl;
        
        if(m.find(current_sum - sum) != m.end())
        {
            cout<<m[current_sum - sum] + 1<<" - "<<i<<endl;
            c++;
        }
        
        m[current_sum] = i;
    }
    cout<<c<<endl;
}

int main()
{
    int sum = -10;
    vector<int> v = {10, 2, -2, -20, 10};
    Required_Indices(v,sum);
    return 0;
}