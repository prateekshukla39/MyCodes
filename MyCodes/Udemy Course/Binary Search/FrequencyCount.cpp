#include<bits/stdc++.h>

using namespace std;

int Lower_bound(vector<int> v, int key)
{
    int s = 0;
    int e = v.size() - 1;
    int ans = -1;
    while(s <= e)
    {
        int mid = (s + e) / 2; 
        if(v[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if(v[mid] > key)
            e = mid - 1;
        else
            s = mid + 1;
    }

    return ans;
}

int Upper_bound(vector<int> v, int key)
{
    int s = 0;
    int e = v.size() - 1;
    
    int ans = -1;
    while(s <= e)
    {
        int mid = (s + e) / 2; 
        if(v[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if(v[mid] > key)
            e = mid - 1;
        else
            s = mid + 1;
    }

    return ans;
}

int main()
{
    vector<int> v = {0,1,1,1,2,3,3,3,3,3,3,4,5,5,5,6};
    cout<<Upper_bound(v, 1) - Lower_bound(v, 1) + 1<<endl;
    return 0;
}