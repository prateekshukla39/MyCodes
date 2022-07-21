#include<bits/stdc++.h>

using namespace std;

string find_window(string s, string p)
{
    int FP[256] = {0};
    int FS[256] = {0};

    for(int i = 0; i<p.length(); i++)
        FP[p[i]]++;
    
    int cnt = 0;
    int start = 0;
    int window_size;
    int start_indx = -1;
    int min_so_far = INT_MAX;

    for(int i = 0; i<s.length(); i++)
    {
        char ch = s[i];
        FS[ch]++;

        if(FP[ch] != 0 && FS[ch] <= FP[ch])
            cnt++;

        if(cnt == p.length())
        {
            while(FS[s[start]] == 0 || FS[s[start]] > FP[s[start]])
            {
                FS[s[start]]--;
                start++;
            }
            window_size = i - start + 1;
            if(window_size < min_so_far)
            {
                min_so_far = window_size;
                start_indx = start;
            }
        }
    }
    if(start_indx == -1)
        return "No window found";
    else
        return s.substr(start_indx, min_so_far);
}

int main()
{
    string s, p;
    cin>>s>>p;
    cout<<find_window(s, p)<<endl;
    return 0;
}
