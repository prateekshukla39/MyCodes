#include<bits/stdc++.h>

using namespace std;

int min_Bars_Helper(string s, int idx, unordered_set<string> &m)
{
    // Base case
    if(s[idx] == '\0')
        return 0;
    // Recursive case
    int ans = INT_MAX;
    string current_String = "";

    for(int i = idx; s[i] != '\0'; i++)
    {
        current_String += s[i];
        if(m.find(current_String) != m.end())
        {
            int remaining_ans = min_Bars_Helper(s, i + 1, m);
            if(remaining_ans != -1)
                ans = min(ans, 1 + remaining_ans);
        }
    } 
    if(ans == INT_MAX)
        return -1;
    return ans;
}

int min_Bars(string s, vector<string> words)
{
    unordered_set<string> m;
    for(auto w : words)
        m.insert(w);
    int output = min_Bars_Helper(s, 0, m);
    
    return output - 1; // function returns an extra bar at the last 
}

int main()
{
    string s = "thequickbrownfox";
    vector<string> words = {"the", "quick", "quickbrown", "brown", "fox"};
    cout<<min_Bars(s, words)<<endl; 
    return 0;
}