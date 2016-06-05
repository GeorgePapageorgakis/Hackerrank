/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int CompareLists(Node *headA, Node* headB)
{
    while ((headA != nullptr) || (headB != nullptr)){
        if ((headA == nullptr) || (headB == nullptr) || (headA->data != headB->data))
            return 0;
        headA=headA->next;
        headB=headB->next;
    }
    return 1;
}