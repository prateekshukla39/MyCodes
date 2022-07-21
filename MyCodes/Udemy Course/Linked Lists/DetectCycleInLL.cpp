#include<bits/stdc++.h>

using namespace std;

class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

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

node* Kreverse(node *head, int k)
{
    // Base case
    if(head == NULL)
        return head;
    // Recursive case
    // Reversing segment of length k
    int count = 1;
    node* prev = NULL;
    node* current = head;
    node* temp = NULL;

    while(current != NULL && count <= k)
    {
        // Store next
        temp = current -> next;
        // Update current
        current -> next = prev;
        // Previous and Current
        prev = current;
        current = temp;
        count++;
    }

    if(current != NULL)
        head -> next = Kreverse(current, k);
    
    return prev;
}

bool containsCycle(node *head)
{
    //Complete this function 
    node* fast = head -> next;
    node* slow = head;

    while(fast && fast -> next)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
        if(fast == slow) 
            return true;
    }
    return false;
}

node* find(node *head, int key)
{
    while(head)
    {
        head = head -> next;
        if(head -> data == key)
            return head;
    }
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
    head -> data = 8;
    head -> next = find(head, 3);
    if(containsCycle(head))
        cout<<"Yes"<<endl;
    else
        cout<<"NO"<<endl;
    
    return 0;
}