#include<bits/stdc++.h>

using namespace std;

int partition(vector<int> &v, int s, int e)
{
    int i = s - 1;
    int pivot = v[e];
    for(int j = s; j <= e; j++)
    {
        if(v[j] < pivot)
        {
            i++;
            swap(v[j], v[i]);
        }
    }

    swap(v[i+1], v[e]);

    return i + 1;
}

int Quick_select(vector<int> &v, int s, int e, int k)
{
    // Base Case
    int p = partition(v, s, e);
    if(p == k)
        return v[p];
    // Recursive Case
    if(k < p)
        Quick_select(v, s, p - 1, k);
    else
        Quick_select(v, p + 1, e, k);
}

int main()
{
    vector<int> v = {10,0,7,6,4,5,2};
    int n = v.size(), k = 3;
    cout<<Quick_select(v, 0, n - 1, k)<<endl;

    return 0;
}