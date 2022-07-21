#include<bits/stdc++.h>

using namespace std;

int main()
{
    char s[1000];
    cin.getline(s,1000);
    char *token = strtok(s, " ");
    while(token != NULL)
    {
        cout<<token<<endl;
        token = strtok(NULL, " ");
    }
    return 0;
}