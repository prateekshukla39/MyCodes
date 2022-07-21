#include<bits/stdc++.h>

using namespace std;

int merge_cross(vector<int> &v, int s, int e)
{
    int i = s;
    int m = (s + e)/2;
    int j = m + 1; 

    vector<int> temp;
    int cnt = 0;

    while(i<=m && j<=e)
    {
        if(v[i] < v[j])
        {
            temp.push_back(v[i]);
            i++;
        }
        else
        {
            cnt += m - i + 1;
            temp.push_back(v[j]);
            j++;
        }
    }

    while(i<=m)
        temp.push_back(v[i++]);

    while(j<=e)
        temp.push_back(v[j++]);

    int k = 0;
    for(int indx = s; indx <= e; indx++)
        v[indx] = temp[k++];
    
    return cnt;
}

int inversions_count(vector<int> &v, int s, int e)
{
    // Base case
    if(s >= e)
        return 0;
    // Recursive case
    int mid = (s + e)/2;
    int c1 = inversions_count(v, s, mid);
    int c2 = inversions_count(v, mid + 1, e);
    int cross = merge_cross(v, s, e);

    return c1 + c2 + cross;
}

int main()
{
    vector<int> v = {0,5,2,3,1};
    int s = 0;
    int e = v.size() - 1;
    cout<<inversions_count(v, s, e)<<endl;

    return 0;
}