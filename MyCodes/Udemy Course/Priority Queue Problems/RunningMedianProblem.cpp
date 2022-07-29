#include<bits/stdc++.h>

using namespace std;

void runningMedian()
{
    int d;
    cin>>d;
    priority_queue<int> leftH;
    priority_queue<int, vector<int>, greater<int>> rightH;
    leftH.push(d);
    float median = d;
    cout<<median<<" ";
    cin>>d;
    while(d != -1)
    {
        if(leftH.size() > rightH.size())
        {
            if(median > d)
            {
                rightH.push(leftH.top());
                leftH.pop();
                leftH.push(d);
            }
            else
                rightH.push(d);
            median = (leftH.top() + rightH.top()) / 2.0;
        }
        else if(leftH.size() == rightH.size())
        {
            if(median > d)
            {
                leftH.push(d);
                median = leftH.top();
            }
            else
            {
                rightH.push(d);
                median = rightH.top();
            }
        }
        else
        {
            if(median > d)
                leftH.push(d);
            else
            {
                leftH.push(rightH.top());
                rightH.pop();
                rightH.push(d);
            }
            median = (leftH.top() + rightH.top()) / 2.0;    
        }
        cout<<median<<" ";
        cin>>d;
    }
    cout<<endl;
    return;
}

int main()
{
    runningMedian();
    return 0;
}
// input : 10 5 2 3 0 12 18 20 22 -1
// output : 10 7.5 5 4 3 4 5 7.5 10