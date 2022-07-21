#include<bits/stdc++.h>

using namespace std;

bool isRedundant(string str)
{
    stack<char> s;
    for(char ch : str)
    {
        if(ch != ')')
            s.push(ch);
        else
        {
            bool operator_found = false;
            while(!s.empty() && s.top() != '(')
            {
                char top = s.top();
                if(top == '+' || top == '-' || top == '*' || top == '/')
                    operator_found = true;
                s.pop();
            }
            s.pop(); // Removing '(' the opening parentheses
            if(!operator_found)
                return true;
        }
    }
    return false;
}

int main()
{
    string exp = "((a+b)+(c))";
    if(isRedundant(exp))
        cout<<"Redundant expression!"<<endl;
    else
        cout<<"Non-Redundant Expression!"<<endl;
    return 0;
}