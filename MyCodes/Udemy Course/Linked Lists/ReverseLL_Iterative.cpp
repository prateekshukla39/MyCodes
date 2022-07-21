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
	if(head == NULL) 
    {
		head = new node(data);
		return;
	}	
	//otherwise 
	node *n = new node(data);
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

void reverse(node* &head)
{
    node* prev = NULL;
    node* current = head;
    node* temp = NULL;

    while(current != NULL)
    {
        // Store next
        temp = current -> next;
        // Update current
        current -> next = prev;
        // Previous and Current
        prev = current;
        current = temp;
    }
    head = prev;
    return;
}

int main()
{
    // Inserting elements in the list
    node* head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    print(head);
    reverse(head);
    print(head);
    return 0;
}