#include<bits/stdc++.h>

using namespace std;

vector<int> sortBalls(vector<int> balls){
    //sort the balls in place in a single pass (O(N) time, O(1) space)
    int low = 0, mid = 0, high = balls.size() - 1;

    while(mid < high)
    {
        if(balls[mid] == 0)
            swap(balls[low++], balls[mid++]);
        else if(balls[mid] == 1)
            mid++;
        else
            swap(balls[mid], balls[high--]);
    }        
    return balls;
}

int main()
{
    vector<int> balls = {0,1,1,2,2,1,0,2,1,0}, result;
    result = sortBalls(balls);
    for(int i : result)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}