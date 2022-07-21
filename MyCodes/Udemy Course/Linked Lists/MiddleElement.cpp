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

int getMid(node* head)
{
    //Complete this function to return kth last element
    node* fast = head -> next;
    node* slow = head;
    
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    
    return slow->data;
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
    insert(head, 7);
    insert(head, 8);
    print(head);
    cout<<getMid(head)<<endl;
    return 0;
}