#include<bits/stdc++.h>

using namespace std;

void solve(stack<int> &s, int k)
{
    // Base case
    if(k == 1)
    {
        s.pop();
        return;
    }
    // Recursive case
    int temp = s.top();
    s.pop();
    solve(s, k - 1);
    s.push(temp);
}

stack<int> midDelete(stack<int> s, int size)
{
    if(size == 0)
        return s;
    int k = (size/2) + 1;
    solve(s, k);
        return s;
}

int main()
{
    stack<int> stack, result;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    stack.push(9);
    int n = stack.size();
    result = midDelete(stack, n);
    while(!result.empty())
    {
        cout<<result.top()<<" ";
        result.pop();
    }
    return 0;
}