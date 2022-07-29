#include<bits/stdc++.h>

using namespace std;

int noOfTripletsinGP(vector<int> v, int r)
{
    int n = v.size();
    unordered_map<long, long> leftM, rightM;
    for(auto i : v)
    {
        rightM[i]++;
        leftM[i] = 0;
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        rightM[v[i]]--;
        if(v[i]%r == 0)
        {
            long a = v[i]/r;
            long b = v[i];
            long c = v[i]*r;
            ans += leftM[a]*rightM[c];
        }
        leftM[v[i]]++;
    }
    return ans;
}

int main()
{
    vector<int> v = {1, 16, 4, 16, 64, 16};
    int r = 4;
    cout<<noOfTripletsinGP(v, r)<<endl;
    return 0;
}
// Ans = 3