/*
Level 1:        3
              /   \
Level 2:     5     2
            / \    /
Level 3:   1   4  6

3 5 2 1 4 6

struct node{
    int data;
    node* left;
    node* right;
}*/
#include <queue>

void LevelOrder(node * root){
    // Base Case
    if (root == nullptr)  return;

    // Create an empty queue for level order tarversal
    queue<node *> q;
    // Enqueue Root and initialize height
    q.push(root);

    while (!q.empty()){
        // Print front of queue and remove it from queue
        node *node = q.front();
        cout << node->data << " ";
        q.pop();

        //Enqueue left child
        if (node->left != nullptr)
            q.push(node->left);
        //Enqueue right child
        if (node->right != nullptr)
            q.push(node->right);
    }
    return;
}
