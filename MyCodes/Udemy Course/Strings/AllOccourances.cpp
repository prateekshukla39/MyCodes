#include<bits/stdc++.h>

using namespace std;

int Occourances(string s, string w, int index)
{
    index = s.find(w, index + 1);
}

int main()
{
    string s("Hi! My name is Prateek. What's your name?"), w;
    getline(cin, w);
    int index = s.find(w); // s.find() returns starting position of the desired substring from the string.
    while(index!=-1)
    {
        cout<<index<<endl;
        index = Occourances(s, w, index);
    }
    return 0;
}