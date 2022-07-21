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

class HBpair
{
    public :
        int height;
        bool balanced;
};

HBpair heightBalanced(node* root)
{
    HBpair P;
    // Base case
    if(root == NULL)
    {
        P.height = 0;
        P.balanced = true;
        return P;
    }
    // Recursive Case

    HBpair Left = heightBalanced(root -> left);
    HBpair Right = heightBalanced(root -> right);
    
    P.height = 1 + max(Left.height, Right.height);

    if(abs(Left.height - Right.height) <= 1 && (Left.balanced && Right.balanced))
        P.balanced = true;
    else
        P.balanced = false;
    
    return P;
}

int main()
{
    node* root = buildTree();
    levelOrderPrint(root);
    if(heightBalanced(root).balanced)
        cout<<"Height is Balanced"<<endl;
    else
        cout<<"Height is not Balanced"<<endl;
    return 0;
}