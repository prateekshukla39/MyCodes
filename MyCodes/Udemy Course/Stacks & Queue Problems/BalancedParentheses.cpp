#include<bits/stdc++.h>

using namespace std;

bool isBalanced(string str)
{
    stack<char> s;
    for(char ch : str)
    {
        switch(ch)
        {
            case '(':
            case '[':
            case '{':   s.push(ch); 
                        break;
            case ')':   {
                if(!s.empty() && s.top() == '(')
                    s.pop();
                else
                    return false;
                
                break;
            }
            case ']':   {
                if(!s.empty() && s.top() == '[')
                    s.pop();
                else
                    return false;
                
                break;
            }
            case '}':   {
                if(!s.empty() && s.top() == '{')
                    s.pop();
                else
                    return false;
                
                break;
            }
            default: continue;
        }
    }
    if(s.empty())
        return true;
    return false;
}

int main()
{
    string exp = "((2+3)*[3])";
    if(isBalanced(exp))
        cout<<"Balanced!"<<endl;
    else
        cout<<"Not balanced!"<<endl;
    return 0;
}