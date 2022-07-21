#include<bits/stdc++.h>

using namespace std;

bool canPlaceBirds(int B, int n, vector<int> nests, int mid)
{
    int birds = 1;
    int lastLocation = nests[0];

    for(int i = 1; i < n - 1; i++)
    {
        int currentLocation = nests[i];
        if(currentLocation - lastLocation >= mid)
        {
            birds++;
            lastLocation = currentLocation; 
            if(birds == B)
                return true;
        }
    }
    return false;
}

int Angry_birds(vector<int> nests, int B)
{
    // Search Space
    int s = 0;
    int n = nests.size();
    int e = nests[n - 1] - nests[0];

    int ans = -1;
    while(s <= e)
    {
        int mid = (s + e) / 2;
        bool canPlace = canPlaceBirds(B, n, nests, mid);
        if(canPlace)
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return ans;
}

int main()
{
    int B = 3;
    vector<int> nests = {1,2,3,4,8,9};
    // Sorting of nests
    sort(nests.begin(), nests.end());
    cout<<Angry_birds(nests, B)<<endl;
    return 0;
}