#include<bits/stdc++.h>

using namespace std;

void permutationWithCaseChange(string input, string output)
{
    // Base Case
    if(input.length() == 0)
    {
        cout << output << endl;
        return;
    }
    // Recursive Case
    string op1 = output, op2 = output;
    op1.push_back(input[0]);
    if(input[0] >= 'a' && input[0] <= 'z')
        op2.push_back(toupper(input[0]));
    else
        op2.push_back(tolower(input[0]));
    input.erase(input.begin() + 0);

    permutationWithCaseChange(input, op1);
    permutationWithCaseChange(input, op2);
    return;
}

int main()
{
    string str = "abc";
    permutationWithCaseChange(str, "");
    return 0;
}