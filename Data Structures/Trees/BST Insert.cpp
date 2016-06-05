/*
	4
   / \
  2   7
 / \
1   3

Value to be inserted is 6.
	 4
   /   \
  2     7
 / \   /
1   3 6

Node defined as:

typedef struct node{
   int data;
   node * left;
   node * right;
}node;
*/

node * insert(node * root, int& value){
    //if node is empty return a new node to it
    if (!root){
        node *tmp = new node();
        tmp->data = value;
        return tmp;
    }
    //recur down the tree till insertion at leaf
    if (root->data > value){
        root->left = insert(root->left, value);
    }
    else if (root->data < value){
        root->right = insert(root->right, value);
    }
    //Do not insert duplicate value
    return root;
}
