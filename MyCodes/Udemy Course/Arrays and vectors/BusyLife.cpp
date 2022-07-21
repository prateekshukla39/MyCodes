#include<bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

int countActivites(vector<pair<int,int> > activities)
{
    sort(activities.begin(), activities.end(), compare);
    int count = 0, prev = activities[0].second;
    for(int i = 0; i < activities.size(); i++)
    {
        if(activities[i].first >= prev)
        {
            prev = activities[i].second;
            count++;
        }
    }
    return count + 1;
}

int main()
{
    vector<pair<int, int> > p{{7,9},{0,10},{4,5},{8,9},{4,10},{5,7}};
    cout<<countActivites(p)<<endl;
    return 0;
}