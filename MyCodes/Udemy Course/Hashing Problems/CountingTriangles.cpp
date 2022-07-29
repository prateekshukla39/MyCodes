#include<bits/stdc++.h>

using namespace std;

class Point{
    public:
        int x, y;
        Point(int x, int y) : x(x), y(y) {};
};

int countingTriangles(vector<Point> &v)
{
    int n = v.size();
    int ans = 0;
    unordered_map<int, int> freq_x;
    unordered_map<int, int> freq_y;

    for(auto i : v)
    {
        int x = i.x;
        int y = i.y;
        freq_x[x]++;
        freq_y[y]++;
    }

    for(auto i : v)
    {
        int x = i.x;
        int y = i.y;
        int fx = freq_x[x];
        int fy = freq_y[y];

        ans += (fx - 1)*(fy - 1);
    }
    return ans;
}

int main()
{
    vector<Point> v;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin>>x>>y;
        Point p(x, y);
        v.push_back(p);
    }
    cout<<countingTriangles(v)<<endl;
    return 0;
}
/* Input:
5
1 2
2 1
2 2
2 3
3 2
*/