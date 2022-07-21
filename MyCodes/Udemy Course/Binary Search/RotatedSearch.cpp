#include<bits/stdc++.h>

using namespace std;

int Rotated_Search(vector<int> v, int key)
{
    int s = 0;
    int n = v.size();
    int e = n - 1;

    while(s <= e)
    {
        int mid = (s + e) / 2;
        if(v[mid] == key)
            return mid;
        if(v[s] <= v[mid])
        {
            if(key >= v[s] && key <= v[mid])
                e = mid - 1;
            else
                s = mid + 1;
        }
        else
        {
            if(key >= v[mid] && key <= v[e])
                s = mid + 1;
            else
                e = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> v = {7,8,9,10,0,1,2,3,4,5,6};
    int key = 10;
    cout<<Rotated_Search(v, key)<<endl;
    return 0;
}