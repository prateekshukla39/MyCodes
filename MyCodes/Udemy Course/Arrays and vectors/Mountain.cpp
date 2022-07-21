#include<bits/stdtr1c++.h>

using namespace std;

int Mountain(vector<int> v) 
{
    vector<int> peaks;
    for(int i = 1; i < v.size()-1; i++)
    {
        if(v[i]>v[i-1] && v[i]>v[i+1])
        {
            peaks.push_back(i);
        }
    }
    int Max = 0;
    for(int i = 0; i < peaks.size(); i++)
    {
        int count = 0, j = peaks[i], k = peaks[i];
        while(j>=1 && v[j]>v[j-1])
        {
            count++;
            j--;
        }
        while(k<=v.size()-2 && v[k]>v[k+1])
        {
            count++;
            k++;
        }
        Max = max(count, Max);
    }
    return Max;
}
int main()
{
    vector<int> v{5,6,1,2,3,4,5,4,3,2,1,0,1,2,3,-2,4};
    cout<<"Max Mountain = "<<Mountain(v)<<endl;
    return 0;
}
        