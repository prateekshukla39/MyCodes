#include<bits/stdc++.h>

using namespace std;

//str is the input the string
string compressString(const string &str){   
    //complete the function to return output string
    string result = "";
    int cnt = 0, i = 1;
    while(str[i] != '\0')
    {
        char ch = str[i];
        if(str[i-1] == ch)
            cnt++;
        else
        {
            result += str[i-1] + to_string(cnt+1);
            cnt = 0;
        }
        i++;
    }
    result += str[str.length()-1] + to_string(cnt+1);
    if(result.length() <= str.length())
        return result;
    else
        return str;
}

int main()
{
    string s;
    cin>>s;
    cout<<compressString(s)<<endl;
    return 0;
}