#include<bits/stdc++.h>

using namespace std;

class Triplet{
    public:
    int element;
    int arrIdx;
    int eleIdx;
    Triplet(int a, int b, int c)
    {
        element = a;
        arrIdx = b;
        eleIdx = c;
    }
};

class Compare{
    public:
    bool operator()(Triplet A, Triplet B)
    {
        return A.element > B.element;
    }
};

vector<int> KWayMerge(vector<vector<int>> arrays)
{
    int k = arrays.size();
    priority_queue<Triplet, vector<Triplet>, Compare> minH;

    vector<int> output;
    for(int i = 0; i < k; i++)
    {
        Triplet T(arrays[i][0], i, 0);
        minH.push(T);
    }
    // Popping and Pushing elements
    while(!minH.empty())
    {
        Triplet top = minH.top();
        minH.pop();
        int ele = top.element;
        int a_idx = top.arrIdx;
        int e_idx = top.eleIdx;
        output.push_back(ele);
        if(e_idx + 1 < arrays[a_idx].size())
        {
            int next_element = arrays[a_idx][e_idx + 1];
            Triplet t(next_element, a_idx, e_idx + 1);
            minH.push(t);
        }
    }
    return output;
}

int main()
{
    vector<vector<int>> V = {{10, 15, 20, 30},
                             {2, 5, 8, 14, 24},
                             {0, 11, 60, 90}}; 
    for(auto i : KWayMerge(V))
        cout<<i<<" ";
    cout<<endl;
    return 0;
}