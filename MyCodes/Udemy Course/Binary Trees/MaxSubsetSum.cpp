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

class Pair{
    public :

    int inc;
    int exc;
};

Pair maxSubsetSum(node* root)
{
    Pair P;
    // Base case
    if(root == NULL)
    {
        P.inc = P.exc = 0;
        return P;
    }
    // Recursive case
    Pair Left = maxSubsetSum(root -> left);
    Pair Right = maxSubsetSum(root -> right);

    P.inc = root -> data + Left.exc + Right.exc;
    P.exc = max(Left.inc, Left.exc) + max(Right.inc, Right.exc);

    return P; 
}

int main()
{
    node* root = buildTree();
    levelOrderPrint(root);
    Pair P = maxSubsetSum(root);
    cout<<"Max Subset Sum = "<<max(P.inc, P.exc)<<endl; 
    return 0;
}