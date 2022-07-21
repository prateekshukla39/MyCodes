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

int kthLastElement(node *head, int k)
{
    //Complete this function to return kth last element
    
    int count = 1;
    node* ptr = head;
    while(ptr -> next)
    {
        ptr = ptr -> next;
        count++;
    }
    int x = count - k;
    node* result = head;
    while(x--)
    {
        result = result -> next;
    }
    return result -> data;
}

// Another way
int kthLastElement2(node *head, int k)
{
    //Complete this function to return kth last element
    
    node* ptr = head;
    while(--k)
    {
        ptr = ptr -> next;
    }
    node* result = head;
    while(ptr -> next)
    {
        result = result -> next;
        ptr = ptr -> next;
    }
    return result -> data;
}

int main()
{
    // Inserting elements in the list
    int k = 3;
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
    cout<<kthLastElement2(head, k)<<endl;
    return 0;
}