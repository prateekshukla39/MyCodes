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

// Helper function 1
node* lca(node* root, int a, int b)
{
    // Base case
    if(root == NULL)
        return NULL;
    if(root -> data == a || root -> data == b)
        return root;
    // Recursive case
    if(a < root -> data && b < root -> data)
        return lca(root -> left, a, b);
    if(a > root -> data && b > root -> data)
        return lca(root -> right, a, b);
    
    return root;    
}

// Helper function 2
int distance(node* root, int target)
{
    // Base case
    if(root == NULL)
        return 0;
    if(root -> data == target)
        return 0;
    // Recursive case
    if(target < root -> data)
        return 1 + distance(root -> left, target);
    else
        return 1 + distance(root -> right, target);
}

//here nodes a and b are the inputs
int shortestDist(node * root, int a, int b)
{
    //Complete this method
    node* LCA = lca(root, a, b);
    int D1 = 0, D2 = 0;
    D1 = distance(LCA, a);
    D2 = distance(LCA, b);

    return D1 + D2;
}

int main()
{
    node* root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for(auto x : arr)
    {
        root = insert(root, x);
    }
    cout<<shortestDist(root, 1, 6)<<endl;
    return 0;
}