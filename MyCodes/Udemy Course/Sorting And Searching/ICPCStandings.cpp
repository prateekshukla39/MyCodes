#include<bits/stdc++.h>

using namespace std;

int badness(vector<pair<string,int> > teams)
{
    //Complete this function to return the min badness
    int n = teams.size();
    int freq[n+1] = {0};

    for(int i = 0; i < n; i++)
        freq[teams[i].second]++;
    
    int curr = 1, i = 1, ans = 0;

    while(curr <= n){
        while(freq[i]--)
        {
            ans += abs(i - curr);
            curr++;
        }
        i++;
    }

    return ans;
}

int main()
{
    vector<pair<string,int> > teams = {{"WinOrBooz", 1},{"BallOfDuty", 2},{"WhoKnows", 2},{"BholeChature", 1},{"DCECoders", 5},{"StrangeCase", 7},{"WhoKnows", 7}};
    cout<<badness(teams)<<endl;
    return 0;
}