#include<bits/stdc++.h>

using namespace std;

pair<int, int> minDifference(vector<int> a, vector<int> b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int f = INT_MAX, first, second, s = INT_MAX;
    int m = a.size() -1, n = b.size() -1;
    for(int i = 0; i < m; i++)
    {
        f = min(f,abs(a[i] - b[0]));
    }
    first = b[0] + f;
    for(int i = 0; i < n; i++)
    {
        s = min(s,abs(first - b[i]));
    }
    second = first + s;
    return {first , second};
}

int main()
{
    vector<int> a{23,5,10,17,30}, b{26,134,135,14,19};
    auto result = minDifference(a, b);
    cout<<"{"<<result.first<<","<<result.second<<"}"<<endl;
    return 0;
}