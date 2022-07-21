#include<bits/stdc++.h>

using namespace std;

class node
{
  public:
   int data;
   node *left;
   node *right;

   node(int data){
       this->data = data;
       left = right  = NULL;
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

bool solve(node* root, int min, int max)
{
    // Base case
    if(root == NULL)
        return true;
    if(root -> data < min || root -> data > max)
        return false;
    // Recursive case
    
    return solve(root -> left, min, root -> data) && solve(root -> right, root -> data, max);
}

bool isBST(node * root)
{
    //complete this method
    return solve(root, INT_MIN, INT_MAX);
}

int main()
{
    node* root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for(auto x : arr)
    {
        root = insert(root, x);
    }
    if(isBST(root))
        cout<<"Is BST"<<endl;
    else 
        cout<<"Not BST"<<endl;
    return 0;
}