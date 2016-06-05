/*
  Insert Node at the begining of a linked list
  Initially head pointer argument could be NULL for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
return back the pointer to the head of the linked list in the below method.
*/
Node* Insert(Node *head,int data)
{
    //create Node if list is empty
    if(head==nullptr){
        head = new Node();
        head->data = data;
        head->next = nullptr;
    }
    //else traverse list and insert at tail
    else{
        Node *aux = head;
        head = new Node();
        head->data = data;
        head->next = aux;
    }
    return head;
}
