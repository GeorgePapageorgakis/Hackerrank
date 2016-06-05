/*
   Find merge point of two linked lists
   Node is defined as
   struct Node {
       int data;
       Node* next;
   }
    Given pointers to the head nodes of linked lists that merge together at some point, find the Node where the two lists merge. 
    It is guaranteed that the two head Nodes will be different, and neither will be NULL.

Example:
[List #1] a--->b--->c
                     \
                      x--->y--->z--->NULL
                     /
     [List #2] p--->q
Create two pointers, pointing to each head, that go forward every time till the end, and then jumps to the beginning of the opposite list, and so on. Advance each pointer by 1 every time, until they meet. This will happen after either one or two passes. O(n) notation.
*/
int FindMergeNode(Node *headA, Node *headB){
    Node *aux1 = headA, *aux2 = headB;
    while (aux1 != aux2){
        aux1 = aux1->next;
        aux2 = aux2->next;
        if (aux1 == nullptr)
            aux1 = headB;
        if (aux2 == nullptr)
            aux2 = headA;
    }
    return aux1->data;
}
