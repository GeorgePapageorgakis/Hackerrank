/*
  Detect loop in a linked list 
  List could be empty also
  Node is defined as 
  struct Node {
     int data;
     struct Node *next;
  }
*/
//Based on Floyd's algorithm concept
int HasCycle(Node* head){
    Node *fast=head, *slow=head;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow){
            return 1;
        }
    }
    return 0;
}