#include<bits/stdc++.h>

using namespace std;

void permutationWithSpaces(string input, string output)
{
    // Base Case
    if(input.length() == 0)
    {
        cout<<output<<endl;
        return;
    }
    // Recursive Case
    string op1 = output, op2 = output;
    op1.push_back('_');
    op1.push_back(input[0]);
    op2.push_back(input[0]);
    input.erase(input.begin() + 0);

    permutationWithSpaces(input, op1);
    permutationWithSpaces(input, op2);
    return;
}

int main()
{
    string str = "abc";
    string output;
    output.push_back(str[0]);
    str.erase(str.begin() + 0);
    permutationWithSpaces(str, output);
    return 0;
}