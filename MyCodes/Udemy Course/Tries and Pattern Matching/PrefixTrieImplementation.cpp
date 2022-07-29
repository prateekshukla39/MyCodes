#include<bits/stdc++.h>

using namespace std;

class node{
    public:
        char data;
        unordered_map<char, node*> m;
        bool isTerminal;
        node(char data) : data(data), isTerminal(false) {};
};

class Tries{
    public:
        node* root;
        Tries()
        {
            root = new node('\0');
        }
        void insert(string word)
        {
            node* temp = root;
            for(char ch : word)
            {
                if(temp -> m.count(ch) == 0)
                {
                    node* n = new node(ch);
                    temp -> m[ch] = n;
                }
                temp = temp -> m[ch];
            }
            temp -> isTerminal = true;
            return;
        }
        bool search(string word)
        {
            node* temp = root;
            for(char ch : word)
            {
                if(temp -> m.count(ch) == 0)
                    return false;
                temp = temp -> m[ch];
            }
            return temp -> isTerminal;
        }
};

int main()
{
    vector<string> words = {"apple", "ape", "no", "news", "not", "never"};
    Tries T;
    for(auto &word : words)
    {
        T.insert(word);
    }
    string input;
    cin>>input;
    if(T.search(input))
        cout<<input<<" is present";
    else
        cout<<input<<" is not present";
    cout<<endl;
    return 0;
}