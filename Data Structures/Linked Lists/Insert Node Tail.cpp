/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data){
    //create Node if list is empty
    if(head==nullptr){  
        head = new Node;
        head->data = data;
        head->next = nullptr;
    }
    //else traverse list and insert at tail
    else{  
        Node *aux = head;  
        while(aux->next !=nullptr){  
            aux = aux->next;  
        }  
        aux->next = new Node;
        aux->next->data = data;
        aux->next->next = nullptr;
    }
    return head;
}