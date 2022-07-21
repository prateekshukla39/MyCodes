#include<bits/stdc++.h>

using namespace std;

string keypad[] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void PrintKeypadOutput(string input, string output, int i = 0)
{
    // Base Case
    if(input[i] == '\0')
    {
        cout<<output<<endl;
        return;
    }
    // Recursive Cases
    int current_digit = input[i] - '0';
    if(current_digit == 0 || current_digit == 1)
        PrintKeypadOutput(input, output, i + 1);
    
    // Keypad
    for(int k = 0; k < keypad[current_digit].size(); k++)
        PrintKeypadOutput(input, output + keypad[current_digit][k], i + 1);
    
    return;
}

int main()
{
    string input;
    cin>>input;
    string output;

    PrintKeypadOutput(input, output);

    return 0;
}