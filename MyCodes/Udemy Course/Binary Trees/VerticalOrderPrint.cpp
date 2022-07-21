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

void treeTravarsal(node* root, int d, map<int, vector<int>> &m)
{
    // Base case
    if(root == NULL)
        return;
    m[d].push_back(root -> data);

    treeTravarsal(root -> left, d - 1, m);
    treeTravarsal(root -> right, d + 1, m);

    return;
}

void verticalOrderPrint(node* root)
{
    int d = 0;
    map<int, vector<int>> m;

    treeTravarsal(root, d, m);

    for(auto p : m)
    {
        vector<int> v = p.second;
        for(auto i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return;
}

int main()
{
    node* root = buildTree();
    levelOrderPrint(root);
    cout<<"Tree Vertical Order Print"<<endl;
    verticalOrderPrint(root);
    return 0;
}