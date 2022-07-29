#include<bits/stdc++.h>

using namespace std;

class node{
    public:
        char data;
        unordered_map<char, node*> m;
        bool isTerminal;
        node(char data) : data(data), isTerminal(false) {};
};

class Suffix_Tries{
    private:
        void insert_helper(string word)
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
    public:
        node* root;
        Suffix_Tries()
        {
            root = new node('\0');
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
        void insert(string word)
        {
            for(int i = 0; word[i] != '\0'; i++)
                insert_helper(word.substr(i));
            return;
        }
};

int main()
{
    string word = "hello";
    vector<string> suffixes = {"llo", "ell", "hello"};
    Suffix_Tries T;
    T.insert(word);
    for(auto suffix : suffixes)
    {
        if(T.search(suffix))
            cout<<"Yes ";
        else
            cout<<"No ";
    }   
    cout<<endl;
    return 0;
}