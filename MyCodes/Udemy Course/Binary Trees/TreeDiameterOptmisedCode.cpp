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

// Diameter optmized
class HDpair
{
    public :
        int height;
        int diameter;
};

HDpair optiDiameter(node* root)
{
    HDpair P;
    // Base Case
    if(root == NULL)
    {
        P.height = P.diameter = 0;
        return P;
    }
    // Recursive Case
    // Height and Diameter are simultaneously computed saving time, hence time complexity is reduced to O(N).
    HDpair Left = optiDiameter(root -> left);
    HDpair Right = optiDiameter(root -> right);

    P.height = 1 + max(Left.height, Right.height);

    int D1 = Left.height + Right.height;
    int D2 = Left.diameter;
    int D3 = Right.diameter;

    P.diameter = max(D1, max(D2, D3));

    return P;
}

int main()
{
    node* root = buildTree();
    levelOrderPrint(root);
    cout<<"Optimized Diameter of Tree = "<<optiDiameter(root).diameter<<endl;
    return 0;
}