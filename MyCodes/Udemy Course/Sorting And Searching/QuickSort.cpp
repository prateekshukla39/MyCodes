#include<bits/stdc++.h>

using namespace std;

int Partition(vector<int> &v, int s, int e)
{
    int pivot = v[e];
    int i = s - 1;

    for(int j = s; j <= e; j++)
    {
        if(v[j] < pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }

    swap(v[i+1], v[e]);

    return i + 1;
}

void Quick_sort(vector<int> &v, int s, int e)
{
    // Base case
    if(s >= e)
        return;
    // Recursive case
    int p = Partition(v, s, e);
    Quick_sort(v, s, p - 1);
    Quick_sort(v, p + 1, e);
}

int main()
{
    vector<int> v = {10,0,7,6,4,5,2};
    int n = v.size();
    Quick_sort(v, 0, n - 1);    

    for(int i : v)
        cout<<i <<" ";
    cout<<endl;

    return 0;
}