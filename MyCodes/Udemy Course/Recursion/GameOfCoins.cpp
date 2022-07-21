#include <bits/stdc++.h>

using namespace std;

int game(vector<int> &nums, int s, int e)
{
    // base case
    if(s > e)
        return 0;
    // recursive case
    // First Choice of player 1 picking the leftmost coin(we took min in the recursive calls because in the next turn player 2 would maximize his winnings)
    int choice1 = nums[s] + min(game(nums, s + 2, e), game(nums, s + 1, e - 1));
    // Second Choice of player 1 picking the Rightmost coin(we took min in the recursive calls because in the next turn player 2 would maximize his winnings)
    int choice2 = nums[e] + min(game(nums, s + 1, e - 1), game(nums, s, e - 2));
    
    return max(choice1, choice2);
}

int MaxValue(int n, vector<int> v)
{
    return game(v, 0, n - 1);
}

int main()
{
    int n = 4;
    vector<int> v = {1, 2, 3, 4};
    cout<<MaxValue(n, v)<<endl;
    return 0;
}