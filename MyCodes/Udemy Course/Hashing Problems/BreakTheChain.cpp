#include<bits/stdc++.h>

using namespace std;

class node{
public:  
  int data;
  node * next;
  node(int data) : data(data) {};
};


 node* breakChain(node* head)
 {
     //Complete this method
     unordered_map<node* , bool> m;
     
     node* temp = head;
     node* prev = NULL;
     while(true)
     {
         m[temp] = true;
         prev = temp;
         temp = temp->next;
         if(m[temp])
             break;
     }
     if(prev!=NULL)
         prev->next = NULL;
     return head;
 }

 int main()
 {
    // Chain of nodes
    node* head = new node(1);
    head -> next = new node(2);
    head -> next -> next = new node(3);
    head -> next -> next -> next = new node(4);
    head -> next -> next -> next -> next = new node(5);
    head -> next -> next -> next -> next -> next = head -> next;

    node* newHead = breakChain(head);
    while(newHead != NULL)
    {
        cout<<newHead -> data<<" ";
        newHead = newHead -> next;
    }
    cout<<endl;
    
    return 0;
 }