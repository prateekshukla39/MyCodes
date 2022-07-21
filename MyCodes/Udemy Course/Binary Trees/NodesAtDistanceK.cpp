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

node *buildTree()
{
    int d;
    cin>>d;
    if(d == -1)
        return NULL;
    
    node *n = new node(d);
    n -> left = buildTree();
    n -> right = buildTree();

    return n;
}

//   								***NOTE : levelOrderBuild function for BFS input type***
/*
node* levelOrderBuild()
{
    int data;
    cin>>data;

    node* root = new node(data);
    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        node* current = q.front();
        q.pop();

        int leftChild, rightChild;
        cin>>leftChild>>rightChild;

        if(leftChild != -1)
        {
            current -> left = new node(leftChild);
            q.push(current -> left);
        }
        if(rightChild != -1)
        {
            current -> right = new node(rightChild);
            q.push(current -> right);
        }
   }
    return root;
}     */

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

void printAtlevelK(node* root, int k)
{
    // Base case
    if(root == NULL)
        return;
    if(k == 0)
    {
        cout<<root -> data<<" ";
        return;
    }
    // Recursive case
    printAtlevelK(root -> left, k - 1);
    printAtlevelK(root -> right, k - 1);
    return;
}

int nodesAtDistanceK(node* root, node* target, int k)
{
    // Base case
    if(root == NULL)
        return -1;
    // Recursive case 
    // If target is found
    if(root == target)
    {
        printAtlevelK(root, k);
        return 0;
    }

    // If target is in the left subtree
    int DL = nodesAtDistanceK(root -> left, target, k);
    if(DL != -1)
    {
        // 2 cases
        // root is at the distance k
        if(DL + 1 == k)
            cout<<root -> data<<" ";
        // print the node from the right subtree which is at a distance k from the target node
        else
            printAtlevelK(root -> right, k -2 - DL);
        return DL + 1; // so as to print the valve in the next call
    }
    // If target is in the right subtree
    int DR = nodesAtDistanceK(root -> right, target, k);
    if(DR != -1)
    {
        // 2 cases
        // root is at the distance k
        if(DR + 1 == k)
            cout<<root -> data<<" ";
        // print the node from the left subtree which is at a distance k from the target node
        else
            printAtlevelK(root -> left, k -2 - DR);
        return DR + 1; // so as to print the valve in the next call
    }
    return -1;
}

int main()
{
    node *root = buildTree();
    node* target = root -> left -> right;
    int k = 2;
    cin>>k;
    levelOrderPrint(root);
    cout<<"Nodes at Distance K : ";
    // cout<<target -> data<<endl;
    nodesAtDistanceK(root, target, k);
    cout<<endl;
    return 0;
}