/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node* headA, Node* headB){
    Node* aux;
    Node* newhead = nullptr;
    if (headA == nullptr){
        if (headB->next ==nullptr)
            return nullptr;
        else
            return headB;
    }
    newhead = (headA->data > headB->data ? headB : headA);
    
    while ((headA != nullptr) && (headB != nullptr)){
        if(headA->data > headB->data){
            while (headA->data > headB->data){
                if ((headB->next !=nullptr) && (headA->data > headB->next->data))
                    headB=headB->next;
                else
                    break;
            }
            aux = headB;
            headB = headB->next;
            aux->next = headA;
        }
        else{
            while (headA->data <= headB->data){
                if ((headA->next !=nullptr) && (headB->data >= headA->next->data))
                    headA=headA->next;
                else
                    break;
            }
            aux = headA;
            headA = headA->next;
            aux->next = headB;
        }
    }
    return newhead;
}