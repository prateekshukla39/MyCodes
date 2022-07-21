#include<bits/stdc++.h>

using namespace std;

void placeTopEle(stack<int> &s, int ele)
{
    // Base case
    if(s.empty())
    {
        s.push(ele);
        return;
    }
    // Recursive case
    int temp = s.top();
    s.pop();
    placeTopEle(s, ele);
    // Induction step
    s.push(temp);
}

void stackReverse(stack<int> &s)
{
    // Base case
    if(s.size() == 1)
        return;
    // Recursive case
    int temp = s.top();
    s.pop();
    stackReverse(s);
    placeTopEle(s, temp);
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
    stackReverse(stack);
    while(!stack.empty())
    {
        cout<<stack.top()<<" ";
        stack.pop();
    }
    return 0;
}