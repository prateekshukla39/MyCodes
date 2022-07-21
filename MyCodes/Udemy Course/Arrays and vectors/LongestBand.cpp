#include<bits/stdc++.h>

using namespace std;

int Longest_Band(vector<int> v) 
{
    unordered_set<int> s;
    for( int x : v )
    {
        s.insert(x);
    }
    int longest = 0;
    for(auto element : s)
    {
        int parent = element - 1;
        if(s.find(parent) == s.end())
        {
            int next_ele = parent + 1, count = 0;
            while(s.find(next_ele) != s.end())
            {
                next_ele++;
                count++;
            }
            if(count>longest)
            longest = count;
        }
    }
    return longest;
}
int main()
{
    vector<int> v{1,9,3,0,18,5,2,4,10,7,12,6};
    cout<<Longest_Band(v)<<endl;
    return 0;
}