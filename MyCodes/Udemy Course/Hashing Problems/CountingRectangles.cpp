#include<bits/stdc++.h>

using namespace std;

class Point{
    public:
        int x;
        int y;
        Point(int x, int y)
        {
            this->x = x;
            this->y = y;
        }
};
class Comapre{
    public:
        bool operator()(Point p1, Point p2)
        {
            if(p1.x == p2.x)
                return p1.y < p2.y;
            return p1.x < p2.x;
        }
};

int noOfRectangles(vector<Point> v)
{
    int ans = 0;
    set<Point, Comapre> s(v.begin(), v.begin() + v.size());
    
    for(auto it = s.begin(); it != prev(s.end()); it++)
        for(auto jt = next(it); jt != s.end(); jt++)
        {
            Point P1 = *it;
            Point P2 = *jt;
            if(P2.x == P1.x || P2.y == P1.y)
                continue;
            Point P3(P1.x, P2.y);
            Point P4(P2.x, P1.y);
            if(s.find(P3) != s.end() && s.find(P4) != s.end())
                ans++;
        }
    return ans/2;
}

int main()
{
    vector<Point> v;
    int n, x, y;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>x>>y;
        Point p(x, y);
        v.push_back(p);
    }
    cout<<noOfRectangles(v)<<endl;
    return 0;
}
/* Input:
8
4 1
4 0
0 0
0 1
1 1
1 0
2 0
2 1 
    Output = 6
*/