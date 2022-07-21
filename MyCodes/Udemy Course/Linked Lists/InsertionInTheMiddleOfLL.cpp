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

void insertInMiddle(node* &head, int data, int pos)
{
	if(pos == 0)
    {
		insert(head, data);
	}
	else
    {
		node * temp = head;
		for(int jump=1;jump<=pos-1;jump++)
        {
			temp = temp->next;
		}
		node * n = new node(data);
		n->next = temp->next;
		temp->next = n;
	}
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
    insertInMiddle(head, 100, 4);
    print(head);
    return 0;
}