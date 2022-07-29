#include<bits/stdc++.h>

using namespace std;

class node{
    public:
        char data;
        unordered_map<char, node*> children;
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
                if(temp -> children.count(ch) == 0)
                {
                    node* n = new node(ch);
                    temp -> children[ch] = n;
                }
                temp = temp -> children[ch];
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
        void insert(string word)
        {
            for(int i = 0; word[i] != '\0'; i++)
                insert_helper(word.substr(i));
            return;
        }
};

void search_Helper(Suffix_Tries T, string document, int i, unordered_map<string, bool> &m)
{
    node* temp = T.root;
    for(int j = i; j < document.size(); j++)
    {
        char ch = document[j];
        if(temp -> children.count(ch) == 0)
            return;
        temp = temp -> children[ch];
        if(temp -> isTerminal)
        {
            string out = document.substr(i, j - i + 1);
            m[out] = true;
        }
    }
    return;
}

void documentSearch(string document, vector<string> words)
{
    Suffix_Tries T;
    for(auto &word : words)
        T.insert(word);
    // Searching part
    unordered_map<string, bool> m;
    for(int i = 0; i < document.size(); i++)
    {
        search_Helper(T, document, i, m);
    }
    for(auto word : words)
        if(m[word])
            cout<<word<<" : Yes "<<endl;
        else
            cout<<word<<" : No "<<endl;
    return;
}

int main()
{
    string document = "little cute cat loves to code in c++, java & python";
    vector<string> words = {"cute cat", "ttle", "cat", "quick", "big"};
    documentSearch(document, words);
    return 0;
}