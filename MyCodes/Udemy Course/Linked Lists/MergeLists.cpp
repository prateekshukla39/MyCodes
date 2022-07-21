#include<bits/stdc++.h> 

using namespace std;

class node
{
    public:
	int data;
	node* next;
    // Constructor
	node(int data)
    {
		this -> data = data;
		next = NULL;
	}
};
//----------Linked List-----------//
void insert(node * &head, int data)
{
    // If there is no node
	if(head == NULL)
    {
		head = new node(data);
		return;
	}	
	//otherwise 
	node * n = new node(data);
	n -> next = head;
	head = n;
}

void print(node *head)
{
    node *ptr = NULL;
    ptr = head;
    while(ptr != NULL)
    {
        cout<<ptr -> data<<"-->";
        ptr = ptr -> next;
    }
    cout<<endl;
}

node* merge(node *a, node* b)
{
	// Base case
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;
	// Recursive case
	node * c;

	if(a -> data < b -> data)
    {
		c = a;
		c -> next = merge(a -> next, b);
	}
	else
    {
		c = b;
		c -> next = merge(a, b -> next);
	}
	return c;
}

int main()
{
    // Inserting elements in the list
    node* a = NULL;
    insert(a, 10);
    insert(a, 9);
    insert(a, 1);
    insert(a, 6);
    node* b = NULL;
    insert(b, 2);
    insert(b, 4);
    insert(b, 3);
    
    print(a);
    print(b);
    node* h = merge(a, b);
    print(h);
    return 0;
}