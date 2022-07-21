#include<bits/stdc++.h>

using namespace std;

int sparse_search(vector<string> str, string S, int s, int e)
{
    int n = str.size();
    while(s <= e)
    {
        int m = (s + e)/2;

        if(str[m] == "")
        {
            int i = m - 1;
            int j = m + 1;
            while(1)
            {
                if(i < s && j > e)
                    return -1;
                else if(i >= s && str[i] != "")
                {
                    m = i;
                    break;
                }
                else if(j < n && str[j] != "")
                {
                    m = j;
                    break;
                }
                else
                {
                    i--;
                    j++;
                }
            }
        }
        if(str[m] == S)
            return m + 1;
        else if(str[m] > S)
            e = m;
        else
            s = m + 1;
    }
    return -1;
}

int main()
{
    vector<string> str = {"ai","","","bat","","","car","cat","","","dog","",""};
    string S = "dog";
    int n = str.size();
    int s = 0;
    int e = n - 1;
    
    cout<<sparse_search(str, S, s, e)<<endl;
    
    return 0;
}