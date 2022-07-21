#include<bits/stdc++.h>

using namespace std;

string solve()
{
    string str;
        cin>>str;
        int n = str.length();
        int i = 0;
        while(i + 2 < n && n >= 3)
        {
            if((str[i] == 'a' && str[i+1] == 'b' && str[i+2] == 'a')||(str[i] == 'b' && str[i+1] == 'a' && str[i+2] == 'b'))
                return "NO";
            else if((str[n - 1] == 'a' && str[n - 2] == 'b')||(str[n - 1] == 'b' && str[n - 2] == 'a')||(str[0] == 'a' && str[1] == 'b')||(str[0] == 'b' && str[1] == 'a'))
                return "NO";
            i++;
        }
        if((n == 2 )&&((str[0] == 'a' && str[1] == 'b')||(str[0] == 'b' && str[1] == 'a')))
            return "NO";
        else if(n == 1)
            return "NO";
        else
            return "YES";
}

int main()
{
    int t;
    cin>>t;
    while (t--)
        cout<<solve()<<endl;
    return 0;
}