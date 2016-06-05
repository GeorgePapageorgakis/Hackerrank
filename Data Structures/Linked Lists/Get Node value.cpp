/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail){
    Node* aux = head;
    int index = 0;
    while(head->next != nullptr){
        head = head->next;
        ++index;
        if(index > positionFromTail)
            aux = aux->next;
    }
    return aux->data;
}