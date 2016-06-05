/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position){
    //TODO: try block for alloc
    Node *tmp = new Node();
    tmp->data = data;
    tmp->next = nullptr;
    
    //create Node if list is empty
    if(head==nullptr){
        head = tmp;      
    }
    //if position == 0
    else if(!position){   
        tmp->next = head;
        head = tmp;
    }
    //else traverse list and insert at N place
    else{
        Node *aux = head;
        int index = 0;
        //traverse list
        while(aux->next != nullptr){
            ++index;
            if (index != position){
                aux = aux->next;
            }
            else{
                break;
            }
        }
        if (aux->next != nullptr){
            tmp->next = aux->next;
            aux->next = tmp;
        }
        else{
            aux->next = tmp;
        }
    }
    return head;
}