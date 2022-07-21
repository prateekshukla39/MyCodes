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
node* levelOrderBuild(node* root)
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
            node* left = new node(leftChild);
            q.push(current -> left);
        }
        if(rightChild != -1)
        {
            node* right = new node(rightChild);
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

int main()
{
    node* root = buildTree();
    levelOrderPrint(root);
    return 0;
}