#include<iostream>

using namespace std;

int MaxMod(int l, int r)
{
    if(l==r)
    return 0;
    int c = r/2;
    if(l>c)
    return r-l;
    else
    return (r-1)/2;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        cout<<MaxMod(l,r)<<endl;
    }
    return 0;
}