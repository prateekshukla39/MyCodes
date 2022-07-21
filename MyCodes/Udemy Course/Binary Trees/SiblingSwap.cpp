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

bool equal(node * root1, node * root2)
{
    //Complete the Function
    // Base cases
    if(root1 == root2)
        return true;
    if(root1 == NULL || root2 == NULL || root1 -> data != root2 -> data)
        return false;
    // Recursive case
    
    return (root1 && root2)&&(root1 -> data == root2 -> data)&&(equal(root1 -> left, root2 -> left) && equal(root1 -> right, root2 -> right))||(equal(root1 -> left, root2 -> right) && equal(root1 -> right, root2 -> left));
}

int main()
{
    // construct the first tree
    node* X = NULL;
 
    X = new node(6);
    X->left = new node(3);
    X->right = new node(8);
    X->left->left = new node(1);
    X->left->right = new node(7);
    X->right->left = new node(4);
    X->right->right = new node(2);
    X->right->left->left = new node(1);
    X->right->left->right = new node(7);
    X->right->right->right = new node(3);
 
    // construct the second tree
    node* Y = NULL;
 
    Y = new node(6);
    Y->left = new node(8);
    Y->right = new node(3);
    Y->left->left = new node(2);
    Y->left->right = new node(4);
    Y->right->left = new node(7);
    Y->right->right = new node(1);
    Y->left->left->left = new node(3);
    Y->left->right->left = new node(1);
    Y->left->right->right = new node(7);
 
    if(equal(X, Y))
        cout<<"Binary tree can be converted";
    else 
        cout<<"Binary tree cannot be converted";
    return 0;
}