#include<bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

node* buildTree()
{
    int data;
    cin>>data;

    if (data == -1)
        return NULL;
    
    node* n = new node(data);
    n -> left = buildTree();
    n -> right = buildTree();

    return n;
}

node* levelOrderBuild()
{
    int data = 0;
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
}

void levelOrderPrint(node*root)
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
            // Insert a new NULL for new level
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
    // node* root = levelOrderBuild();
    node* root = buildTree();
    levelOrderPrint(root);
    return 0;
}