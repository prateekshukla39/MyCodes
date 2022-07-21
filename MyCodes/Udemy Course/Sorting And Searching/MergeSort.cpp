#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> &v, int s, int e)
{
    int i = s;
    int m = (s+e)/2;
    int j = m + 1;

    vector<int> temp;
    while(i <= m && j <= e)
    {
        if(v[i] < v[j])
        {
            temp.push_back(v[i]);
            i++;
        }
        else
        {
            temp.push_back(v[j]);
            j++;
        }
    }

    // Remaining elements if j is exhausted
    while(i<=m)
    {
        temp.push_back(v[i]);
        i++;
    }
    // Remaining elements if i is exhausted
    while(j<=e)
    {
        temp.push_back(v[j]);
        j++;
    }
    int k = 0;
    for(int indx = s; indx <= e; indx++)
        v[indx] = temp[k++];
} 

void mergeSort(vector<int> &v, int s, int e)
{
    // Base case
    if(s>=e)
        return;
    // Recursive case
    int mid = (s+e)/2;
    mergeSort(v, s, mid);
    mergeSort(v, mid + 1, e);

    return merge(v, s, e);
}

int main()
{
    vector<int> v = {1,6,0,7,3,2,9,10};
    int s = 0, e = v.size() - 1;
    mergeSort(v, s, e);
    for(int i : v)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}