#include<bits/stdc++.h>

using namespace std;

pair<int,int> subarraySorting(vector<int> a)
{
    //Expected Optimal Complexity O(n) Time, O(1) Space
    //may be start with O(NLogN) and try to improve
    //complete this function
    int n = a.size();
    int s = 0, e = n-1, i, max, min;
 
    for (s = 0; s < n-1; s++)
    {
        if (a[s] > a[s+1])
        break;
    }
    for(e = n - 1; e > 0; e--)
    {
        if(a[e] < a[e-1])
        break;
    }
    max = a[s]; 
    min = a[s];
    for(i = s + 1; i <= e; i++)
    {
        if(a[i] > max)
        max = a[i];
        if(a[i] < min)
        min = a[i];
    }
    
    for( i = 0; i < s; i++)
    {
        if(a[i] > min)
        {
            s = i;
            break;
        }    
    }
    
    for( i = n -1; i >= e+1; i--)
    {
        if(a[i] < max)
        {
            e = i;
            break;
        }
    }
    if(s != n - 1)
        return {s, e};
    else
        return {-1,-1};
}
int main()
{
    vector<int> v = {0,2,4,7,10,11,7,12,13,14,16,19,29};
    pair<int, int> p = subarraySorting(v);

    cout<<p.first << " " << p.second << endl;
    
    return 0;
}