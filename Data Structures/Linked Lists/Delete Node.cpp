/*
  Delete Node at a given position in a linked list
  NOTE: assume we precheck position and does not fall out of index
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position){
    Node* aux = head;
    //if position == 0
    if(!position){
        head = aux->next;
        delete aux;
    }
    //else traverse list and delete at N place
    else{
        int index = 0;
        //traverse list
        while(aux->next != nullptr){
            ++index;
            if (index < position){
                aux = aux->next;
            }
            else{
                break;
            }
        }
        if (aux->next != nullptr){
            Node* tmp = aux->next;
            aux->next = aux->next->next;
            delete tmp;
        }
    }
    return head;
}
