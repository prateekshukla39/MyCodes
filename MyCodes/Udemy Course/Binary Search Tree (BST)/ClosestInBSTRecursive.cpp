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

void closest(node* root, int target, int &minDiff, int &minDiff_Key)
{
    // Base case
    if(root == NULL)
        return;
    if(root -> data == target)
    {
        minDiff_Key = root -> data;
        return;
    }
    // Recursive case
    int current_diff = abs(root -> data - target);
    if(current_diff < minDiff)
    {
        minDiff = current_diff;
        minDiff_Key = root -> data;
    }
    if(root -> data < target)
        closest(root -> right, target, minDiff, minDiff_Key);
    else
        closest(root -> left, target, minDiff, minDiff_Key);
    return;
}

int findClosestInBST(node* root, int target)
{
    int minDiff = INT_MAX;
    int minDiff_Key = -1;
    closest(root, target, minDiff, minDiff_Key);

    return minDiff_Key;
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