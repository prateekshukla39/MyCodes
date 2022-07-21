#include<bits/stdc++.h>

using namespace std;

int main()
{
    int arr[256] = {0};
    string s;
    cin>>s;
    char ch;
    cin>>ch;
    for(int i=0; i<s.length(); i++)
        arr[(int)s[i]]++; 
    cout<<arr[ch]<<endl;

    return 0;
}
