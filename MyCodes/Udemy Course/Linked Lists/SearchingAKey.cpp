#include<bits/stdc++.h>

using namespace std;

class nodee
{
public:
	int data;
	nodee* next;
    
    // Constructor
	nodee(int data)
	{
		this->data = data;
		next = NULL;
	}
};

bool isPresent(nodee * head, int key)
{
    //Complete this function 
    nodee *ptr = NULL;
    ptr = head;
    
    while(ptr != NULL)
    {
        if(ptr -> data == key)
            return true;
        ptr = ptr -> next;
    }
    return false;
}

void insert(nodee* &head, int data)
{
    // For first node
    if(head == NULL)
    {
        head = new nodee(data);
        return;
    }
    // Otherwise
    nodee *ptr = new nodee(data);
    ptr -> next = head;
    head = ptr;
}

int main()
{
    // Inserting elements in the list
    nodee* head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    cout<<isPresent(head, 3)<<endl;
    return 0;
}