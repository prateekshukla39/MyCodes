#include<bits/stdc++.h>

using namespace std;

vector<char> firstNonRepeatingCharacter(string S)
{
    vector<char> ans;
    queue<char> q;
    int freq[27] = {0};
    for(int i = 0; S[i] != '\0'; i++)
    {
        q.push(S[i]);
        freq[S[i] - 'a']++;
        while(!q.empty())
        {
            int indx = q.front() - 'a';
            if(freq[indx] > 1)
                q.pop();
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty())
            ans.push_back('0');
    }
    return ans;
}

int main()
{
    vector<char> ans = firstNonRepeatingCharacter("aabccbcd");
    for(char ch : ans)
        cout<<ch;
    cout<<endl;
    return 0;
}