#include<bits/stdc++.h>

using namespace std;

class node{
    public:
        node* left;
        node* right;
};

class Tries{
        node* root;
    public:
        Tries()
        {
            root = new node();
        }

        void insert(int n)
        {
            node* temp = root;
            for(int i = 31; i >= 0; i--)
            {
                int bit = (n >> i) & 1;
                if(bit == 0)
                {
                    if(temp -> left == NULL)
                        temp -> left = new node();
                    temp = temp -> left;
                }
                else
                {
                    if(temp -> right == NULL)
                        temp -> right = new node();
                    temp = temp -> right;
                }
            }
            return;
        }

        int max_xor_helper(int value)
        {
            node* temp = root;
            int current_ans = 0;
            for(int i = 31; i >= 0; i--)
            {
                int bit = (value >> i) & 1;
                if(bit == 0)
                {
                    if(temp -> right != NULL)
                    {
                        temp = temp -> right;
                        current_ans += (1 << i);
                    }
                    else
                        temp = temp -> left;
                }
                else
                {
                    if(temp -> left != NULL)
                    {
                        temp = temp -> left;
                        current_ans += (1 << i);
                    }
                    else
                        temp = temp -> right;
                }
            }
            return current_ans;
        }

        int max_xor(vector<int> input)
        {
            int max_xor = 0;
            for(int i = 0; i < input.size(); i++)
            {
                int value = input[i];
                insert(value);
                int current_xor = max_xor_helper(value);
                max_xor = max(max_xor, current_xor);
            }
            return max_xor;
        }
};

int main()
{
    vector<int> input = {3, 5, 25, 10, 9, 2};
    Tries T;
    cout<<T.max_xor(input)<<endl;
    return 0;
}