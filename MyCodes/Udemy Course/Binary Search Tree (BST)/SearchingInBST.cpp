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

// void printBST(node* root)
// {
//     // Base case
//     if(root == NULL)
//         return;
//     // Recursive case
//     // left -> root -> right (Inorder Traversal)
//     printBST(root -> left);
//     cout<<root -> data<<" ";
//     printBST(root -> right);

//     return;
// }

bool search(node* root, int key)
{
    // Base cases
    if(root == NULL)
        return false;
    if(root -> data == key)
        return true;
    // Recursive case
    if(key < root -> data)
        return search(root -> left, key);
    else
        return search(root -> right, key);
}

int main()
{
    node* root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    int key = 6;
    for(auto x : arr)
    {
        root = insert(root, x);
    }
    // printBST(root);
    if(search(root, key))
        cout<<"Root found!"<<endl;
    else
        cout<<"Root not found!"<<endl;
    return 0;
}
