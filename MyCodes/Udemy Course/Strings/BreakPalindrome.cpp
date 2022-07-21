#include<bits/stdc++.h>

using namespace std;

string breakPalindrome(string palindrome) 
{
    int n = palindrome.length();
    if(n == 1)
        return "";
    for(int i = 0; i < n; i++)
    {
        int j = n - 1 - i;
        if(i == j)
            continue;
        else
        {
            if(palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
    }
    palindrome[n-1] = 'b';
    return palindrome;
}

int main()
{
    string palindrome;
    cin >> palindrome;
    cout<<breakPalindrome(palindrome)<<endl;
    return 0;
}