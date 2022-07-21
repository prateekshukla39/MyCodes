#include<bits/stdc++.h>

using namespace std;

string Largest_Unique_String(string s)
{
    int n = s.length(), Window_len = 0, Max_Window_len = 0, Window_start = -1;
    unordered_map<char, int> m;
    int i = 0, j = 0;
    while(j < n) 
    {
        if(m.count(s[j]) && m[s[j]] >= i)
        {
            i = m[s[j]] + 1;
            Window_len = j - i;
        }
        
        m[s[j]] = j;
        Window_len++;
        j++;

        if(Window_len > Max_Window_len)
        {
            Max_Window_len = Window_len;
            Window_start = i;
        }
    }
    return s.substr(Window_start, Max_Window_len);
}

int main()
{
    string s = "bcedfabac";
    cout<<Largest_Unique_String(s)<<endl;
    return 0;
}