#include<bits/stdc++.h>

using namespace std;

string spell(int n)
{
    vector<string> v = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    return v[n];
}

string SpellANumber(int n)
{
    // Base case
    if(n == 0)
        return "";
    // Recursive case
    return SpellANumber(n/10) + spell(n%10);
}

int main()
{
    int n;
    cin>>n;
    cout<<SpellANumber(n);
    return 0;
}