#include<bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildMinHeightBST(vector<int> arr, int start, int end)
{
    // Base case
    if(start > end)
        return NULL;
    // Assigning Nodes

    int mid = (start + end)/2;
    node* root = new node(arr[mid]);
    // Recursive Cases
    root -> left = buildMinHeightBST(arr, start, mid - 1);
    root -> right = buildMinHeightBST(arr, mid + 1, end);

    return root;
}

void levelOrderPrint(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp = q.front();
        if(temp == NULL)
        {
            q.pop();
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else
        {
            q.pop();
            cout<<temp -> data<<" ";

            if(temp -> left)
                q.push(temp -> left);

            if(temp -> right)
                q.push(temp -> right);
        }
    }
    return;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int n = arr.size();
    node* root = buildMinHeightBST(arr, 0, n - 1);
    levelOrderPrint(root);

    return 0;
}