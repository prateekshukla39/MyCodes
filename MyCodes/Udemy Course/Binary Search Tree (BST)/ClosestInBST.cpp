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

int findClosestInBST(node* root, int target)
{
    int closest;
    int diff = INT_MAX;

    node* temp = root;

    while(temp != NULL)
    {
        int current_diff = abs(temp->data - target);
        if(current_diff == 0)
            return temp->data;
        // Updating diff and closest
        if(current_diff < diff)
        {
            diff = current_diff;
            closest = temp -> data;
        }
        // Left or Right
        if(temp -> data < target)
            temp = temp -> right;
        else
            temp = temp -> left;
    }
    return closest;
}

int main()
{
    node* root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    int key;
    for(auto x : arr)
    {
        root = insert(root, x);
    }
    cin>>key;
    cout<<"Closest to "<<key<<" is : "<<findClosestInBST(root, key)<<endl;
    return 0;
}