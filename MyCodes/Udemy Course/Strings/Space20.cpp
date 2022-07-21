#include<bits/stdc++.h>

using namespace std;

void Change(char *a)
{
    int  cnt = 0;
    for(int i = 0; a[i]!='\0'; i++)
    {
        if(a[i] == ' ')
            cnt++;
    }
    int indx = strlen(a) + 2*cnt;
        a[indx] = '\0';
    for(int i = strlen(a) - 1; i>=0; i--)
    {
        if(a[i] == ' ')
        {
            a[indx-1] = '0';
            a[indx-2] = '2';
            a[indx-3] = '%';
            indx = indx - 3;
        }
        else
        {
            a[indx - 1] = a[i];
            indx--;
        }
    }
}

int main()
{
    char S[1000];
    cin.getline(S,100);
    Change(S);
    cout<<S<<endl;
    return 0;
}