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

class LinkedList{
    public:
    node* head;
    node* tail;
};

LinkedList tree2LL(node* root)
{
    LinkedList l;
    // Base case
    if(root == NULL)
    {
        l.head = l.tail = NULL;
        return l;
    }
    // 4 Recursive cases
    if(root -> left == NULL && root -> right == NULL)
        l.head = l.tail = root;
    else if(root -> left != NULL && root -> right == NULL)
    {
        LinkedList leftLL = tree2LL(root -> left);
        leftLL.tail -> right = root;

        l.head = leftLL.head;
        l.tail = root;
    }
    else if(root -> left == NULL && root -> right != NULL)
    {
        LinkedList rightLL = tree2LL(root -> right);
        root -> right = rightLL.head;

        l.head = root;
        l.tail = rightLL.tail;
    }
    else
    {
        LinkedList leftLL = tree2LL(root -> left);
        LinkedList rightLL = tree2LL(root -> right);
        leftLL.tail -> right = root;
        root -> right = rightLL.head;

        l.head = leftLL.head;
        l.tail = rightLL.tail;
    }
    return l;
}

int main()
{
    node* root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for(auto x : arr)
    {
        root = insert(root, x);
    }
    levelOrderPrint(root);
    LinkedList l = tree2LL(root);

    node* temp = l.head;
    while(temp != NULL)
    {
        cout<<temp -> data<<" ";
        temp = temp -> right;
    }
    cout<<endl;
    return 0;
}