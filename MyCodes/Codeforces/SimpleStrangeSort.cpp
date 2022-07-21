#include<bits/stdc++.h>

using namespace std;

int NoOfSorts(vector<int> v)
{
    int count = 0;
    while(!is_sorted(v.begin(),v.end()))
    {
        for(int i = count%2; i<v.size()-1; i+=2)
        {
            if(v[i] > v[i+1])
            swap(v[i],v[i+1]);
        }
        count++;
    }
    return count;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0; i<n; i++)
        { 
            int inp;
            cin>>inp;
            v.push_back(inp);
        }
        cout<<NoOfSorts(v)<<endl;
    }
    return 0;
}