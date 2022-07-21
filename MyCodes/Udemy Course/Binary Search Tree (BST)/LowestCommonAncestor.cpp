#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node*left;
	node*right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* lca(node*root, int a, int b)
{
    //Complete this function and return address of the node
    // Base case
    if (root == NULL)
		return NULL;
	if (root->data == a or root->data == b) 
		return root;
    // Recursive cases
    if(a < root -> data && b < root -> data)
        return lca(root -> left, a, b);
    if(a > root -> data && b > root -> data)
        return lca(root -> right, a, b);
    
    return root;
}

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

int main()
{
    node* root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for(auto x : arr)
    {
        root = insert(root, x);
    }
    cout<<lca(root, 1, 6) -> data<<endl;
    return 0;
}