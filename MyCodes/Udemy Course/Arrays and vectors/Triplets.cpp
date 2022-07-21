#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > Triplets(vector<int> v, int sum)
{
    vector<vector<int> > result;
    sort(v.begin(), v.end());
    for(int i=0; i<v.size()-2; i++)
    {
        int j = i+1, k = v.size()-1;
        while(k>j)
        {
            int currentSum = v[i];
            currentSum += v[j];
            currentSum += v[k];
            if(currentSum==sum)
            {
                result.push_back({v[i], v[j], v[k]});
                j++; 
                k--;
            }
            else if(currentSum>sum)
            {
            k--;
            }
            else{
            j++;    
            }
        }
    }    
    return result;
}
int main()
{
    vector<int> v{1,2,3,4,5,6,7,8,9,15};
    int sum = 18;
    auto result = Triplets(v, sum);
    for(auto i : result)
    {
        for(auto j : i)
        {
            cout<< j << " " ;
        }
        cout<< endl;
    }
    return 0;
}