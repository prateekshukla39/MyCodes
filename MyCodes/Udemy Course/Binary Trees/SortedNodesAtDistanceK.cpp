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

void storeAtlevelK(node* root, int k, vector<int> &s)
{
    // Base case
    if(root == NULL)
        return;
    if(k == 0)
    {
        s.push_back(root -> data);
        return;
    }
    // Recursive case
    storeAtlevelK(root -> left, k - 1, s);
    storeAtlevelK(root -> right, k - 1, s);
    return;
}

int NodesAtDistanceK(node* root, node* target, int k, vector<int> &s)
{
    // Base case
    if(root == NULL)
        return -1;
    // Recursive case 
    // If target is found
    if(root == target)
    {
        storeAtlevelK(root, k, s);
        return 0;
    }

    // If target is in the left subtree
    int DL = NodesAtDistanceK(root -> left, target, k, s);
    if(DL != -1)
    {
        // 2 cases
        // root is at the distance k
        if(DL + 1 == k)
            s.push_back(root -> data);
        // print the node from the right subtree which is at a distance k from the target node
        else
            storeAtlevelK(root -> right, k -2 - DL, s);
        return DL + 1; // so as to print the valve in the next call
    }
    // If target is in the right subtree
    int DR = NodesAtDistanceK(root -> right, target, k, s);
    if(DR != -1)
    {
        // 2 cases
        // root is at the distance k
        if(DR + 1 == k)
            s.push_back(root -> data);
        // print the node from the left subtree which is at a distance k from the target node
        else
            storeAtlevelK(root -> left, k -2 - DR, s);
        return DR + 1; // so as to print the valve in the next call
    }
    return -1;
}

vector<int> nodesAtDistanceK(node *root, node *target, int k)
{
    vector<int> s;
    NodesAtDistanceK(root, target, k, s);
    sort(s.begin(), s.end());
    return s;
}

int main()
{
    node* root = buildTree();
    node* target = root -> left -> right;
    int k;
    cin>>k;
    levelOrderPrint(root);
    for(auto i : nodesAtDistanceK(root, target, k))
        cout<<i<<" ";
    cout<<endl;
    return 0;
}