/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node{
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* Reverse(Node* head){
    Node * prev=nullptr; 
    Node * next=nullptr;
    //head is always current
    while(head != nullptr){
        next = head->next;
        head->next = prev;
        head->prev = next;
        prev = head;
        head = next;
    }
    return prev;
}