#include<bits/stdc++.h>

using namespace std;

char *Mystrtok(char *str, const char dlim)
{
    static char *input = NULL;
    if(str != NULL)
        input = str;
    if(input == NULL)
        return NULL;
    char *token = new char[strlen(input) + 1];
    int i = 0;
    for( ;input[i] != '\0'; i++)
    {
        if(input[i] != dlim)
            token[i] = input[i];
        else
        {
            token[i] = '\0';
            input = input + i + 1;
            return token;
        }
    }
    token[i] = '\0';
    input = NULL;
    return token;
}

int main()
{
    char str[1000];
    cin.getline(str,1000);
    char *token = Mystrtok(str, ' ');
    while(token!=NULL)
    {
        cout<<token<<endl;
        token = Mystrtok(NULL, ' ');
    }
    return 0;
}