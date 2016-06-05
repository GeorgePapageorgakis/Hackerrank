/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head){
    Node * prev=nullptr; 
    Node* next=nullptr;
    //head is always current
    while(head != nullptr){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}