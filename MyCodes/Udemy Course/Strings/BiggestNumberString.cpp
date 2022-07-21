#include<bits/stdc++.h>
using namespace std;

vector<string> nums_to_String(vector<int> v)
{
    vector<string> result;
    for (int i = 0; i < v.size(); i++)
    {
        string s = to_string(v[i]);
        result.push_back(s);
    }
    return result;
}

bool compare(string s1, string s2)
{
    return s1 + s2 > s2 + s1;
}

string concatenate(vector<int> numbers){
    //complete this method and return the largest number you can form as a string
    vector<string> vs;
    vs = nums_to_String(numbers);
    sort(vs.begin(), vs.end(), compare);
    string result = "";
    for(auto ch : vs)
        result += ch;
    
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin>> v[i];
    cout<<concatenate(v)<<endl;
    return 0;
}