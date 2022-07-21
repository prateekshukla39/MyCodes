#include<bits/stdc++.h>

using namespace std;

int sum(vector<int> v, int i, int j)
{
    int sum = 0;
    for (int k = i; k < j; k++) 
        sum += v[k];
    return sum;
}

int calc(vector<int> v, int s, int e, int k)
{
    // Base case
    if (s > e)
        return 0;
    // Recursive case
    int result = INT_MIN;
    for (int i = 0; i <= k; i++)
    {
        int ans = sum(v, s, (s + i)) + sum(v, e - (k - i) + 1, e + 1);
        int choice = INT_MAX;
        for (int j = 0; j <= k; j++)
            choice = min(choice, calc(v, (s + i) + j, e - (k - i) - k + j, k));
        result = max(result, ans + choice);
    }
    return result;
}

int MaxValue(int n, vector<int> v, int k)
{
    return calc(v, 0, n - 1, k); 
}

int main()
{
    vector<int> v = {10, 15, 20, 9, 2, 5};
    int k = 2;
    cout<<MaxValue(v.size(), v, k);
    return 0;
}
