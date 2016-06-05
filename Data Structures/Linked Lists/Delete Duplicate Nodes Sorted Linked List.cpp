/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head){
    Node* aux;
    if(head==nullptr){  
        return head;
    }
    aux = head;
    while(aux->next != nullptr){
        if (aux->data == aux->next->data){
            //temp store node to be deleted
            Node* todelete = aux->next;
            //update next
            aux->next = aux->next->next;
            //delete node
            delete todelete;                      
        }
        else{
            aux = aux->next;  
        }
    }
    return head;
}