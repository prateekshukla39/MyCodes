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

node* inorderSuccessorInBST(node* root, node* target)
{
    // When right subtree exists
    if(target -> right != NULL)
    {
        node* temp = target -> right;
        while(temp -> left != NULL)
            temp = temp -> left;
        return temp;
    }
    // Otherwise
    node* temp = root;
    node* succ = NULL;
    while(temp != NULL)
    {
        if(temp -> data > target -> data)
        {
            succ = temp;
            temp = temp -> left;
        }
        else if(temp -> data < target -> data)
            temp = temp -> right;
        else
            break;
    }
    return succ;
}

int main()
{
    node* root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for(auto x : arr)
    {
        root = insert(root, x);
    }
    node* target = root -> left -> right -> right;
    node* target2 = root -> right;
    cout<<"Inorder Successor of "<<target -> data <<" in this Tree is : "<<inorderSuccessorInBST(root, target) -> data<<endl;
    return 0;
}
