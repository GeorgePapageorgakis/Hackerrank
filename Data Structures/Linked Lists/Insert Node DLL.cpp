/*
    Insert Node in a doubly sorted (ascending) linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node  {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data){
    Node *aux = head, *tmp = new Node();
    tmp->data = data;
    tmp->prev = nullptr;
    tmp->next = nullptr;
    
    //if list is empty
    if (head == nullptr)
        head = tmp;
    else{
        if (aux->data > data)
            head = tmp;
        while(aux != nullptr){
            if (aux->data > data){
                tmp->prev = aux->prev;
                tmp->next = aux;
                if (aux->prev != nullptr)
                    aux->prev->next = tmp;
                aux->prev = tmp;
                break;
            }
            else{
                //if tmp is to be placed at tail
                if (aux->next == nullptr){
                    tmp->prev = aux;
                    aux->next = tmp;
                    break;
                }
                else
                    aux = aux->next;    
            }     
        }
    }
    return head;
}
