#include<bits/stdc++.h>

using namespace std;

class Node{
	
	public:
		char ch;
		bool isTerminal;
		unordered_map<char, Node*> children;
	
		Node(char ch)
		{
			this -> ch = ch;
			isTerminal = false;
		}
};

class Trie{
	Node* root;
public:
	Trie()
	{
		root = new Node('\0');
	}
	
	Node* getRoot()
	{
		return root;
	}
	
	void insert(string s)
	{
		
		Node* temp = root;
		for(char ch : s)
		{
			if(temp -> children.count(ch) == 0)
			{
				temp -> children[ch] = new Node(ch);
			}
			temp = temp -> children[ch];
		}
		temp -> isTerminal = true;
		return;
	}
};

bool isSpecial(Trie T, Node* root, string word, int i, int cnt) 
{
	//entire string is finished
	// Base Case
	if(i == word.length())
	{
		// cout<<"Count is "<<cnt + 1 <<"  and "<<root->ch<<endl;
		return root -> isTerminal and (cnt + 1) >=2;
	}
	// Recursive case
	char ch = word[i];
	// trie is finished
	if(root -> children.count(ch) == 0)
		return false;
	//bewkoofon vali mistake <---
	root = root -> children[ch];
	//current node is terminal 
	if(root -> isTerminal)
	{
		bool remaining = isSpecial(T, T.getRoot(), word, i + 1, cnt + 1);
		if(remaining == true)
			return true;
	}
	return isSpecial(T, root, word, i + 1, cnt);
}


vector<string> googlyStrings(vector<string> strings) 
{
  // Write your code here.
	Trie T;
	
	for(auto str : strings)
		T.insert(str);
	vector<string> output = {};
	// for every word in the list of strings
	//check if it can be formed using atleast 2 words from the trie
	
	for(auto s : strings)
	{
	  //cnt how many words are repeated to form a given string
		int cnt = 0;
		Node* temp = T.getRoot();
		if(isSpecial(T, temp, s, 0, cnt))
		{
			output.push_back(s);
		}
	}
	
  return output;
}

int main()
{
    vector<string> input = {"goo", "gle", "google", "le", "googly", "ly", "g", "googoole"};
    for(auto word : googlyStrings(input))
        cout<<word<<endl;
    return 0;
}