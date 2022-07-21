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

//  								***NOTE : levelOrderBuild function for BFS input type***
/*
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
}*/

//Input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
node* buildTree()
{
	int d;
	cin>>d;

	if(d==-1)
		return NULL;

	node* n = new node(d);
	n->left = buildTree();
	n->right = buildTree();

	return n;
}
/* Todo: Implement Level Order Traversal
Expected Output
1
2 3
4 5 6
7
*/

void levelOrderPrint(node*root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty())
    {
		node* temp = q.front();
		if(temp==NULL)
        {
			cout<<endl;
			q.pop();
			//insert a new null for the next level
			if(!q.empty())
				q.push(NULL);
		}
		else{
			q.pop();
			cout<<temp->data<<" ";

			if(temp->left)
				q.push(temp->left);

			if(temp->right)
				q.push(temp->right);
		}
	}
	return;
}

//Helper Function : Height of the Tree
int height(node* root)
{
    // Base case
	if(root == NULL)
		return 0;
    // Recursive case
	int h1 = height(root -> left);
	int h2 = height(root -> right);

	return 1 + max(h1, h2);
}

// Diameter
// Time Complexity?
int diameter(node* root)
{
	//base case 
	if(root == NULL)
		return 0;

	//rec case
	int D1 = height(root -> left) + height(root -> right);
	int D2 = diameter(root -> left);
	int D3 = diameter(root -> right);

	return max(D1, max(D2, D3));
}

int main()
{
    node* root = buildTree();
    levelOrderPrint(root);
    cout<<"Diameter of tree = "<<diameter(root)<<endl;
    return 0;
}