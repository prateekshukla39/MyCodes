#include<bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this -> data = data;
        left = right = NULL;
    }
};

node* insert(node* root, int key)
{
    // Base case
    if(root == NULL)
        return new node(key);
    // Recursive case
    if(key < root -> data)
        root -> left = insert(root -> left, key);
    else
        root -> right = insert(root -> right, key);
    
    return root;
}

void printBST(node* root)
{
    // Base case
    if(root == NULL)
        return;
    // Recursive case
    // left -> root -> right (Inorder Traversal)
    printBST(root -> left);
    cout<<root -> data<<" ";
    printBST(root -> right);

    return;
}

int main()
{
    node* root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for(auto x : arr)
    {
        root = insert(root, x);
    }
    printBST(root);
    return 0;
}
