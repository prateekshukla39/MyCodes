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
	node * c;
	// Base case
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;
	// Recursive case

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

node* midPoint(node* head)
{
    node* fast = head -> next;
    node* slow = head;

    while(fast && fast -> next)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

node* mergeSort(node* head)
{
    // Base case
    if(head == NULL || head -> next == NULL)
        return head;
    // Recursive case
    node* mid = midPoint(head);
    node* a = head;
    node* b = mid -> next;
    mid -> next = NULL;
    a = mergeSort(a);
    b = mergeSort(b);

    merge(a, b);
}

int main()
{
    // Inserting elements in the list
    node* a = NULL;
    insert(a, 10);
    insert(a, 9);
    insert(a, 1);
    insert(a, 6);
        
    print(a);
    node* h = mergeSort(a);
    print(h);
    return 0;
}