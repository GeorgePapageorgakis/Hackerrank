 /*
	 3
   /   \
  5     2
 / \   / \
1   4 6   7
 \       /
  9     8
Top View : 1 -> 5 -> 3 -> 2 -> 7

Given a pointer to the root of a binary tree. Print the top view of the binary tree. 
struct node{
    int data;
    node* left;
    node* right;
};

*/
void goLeft(node *node) {
    if(node->left != nullptr)
        goLeft(node->left);
    cout << node->data << " ";
}
void goRight(node *node) {
    cout << node->data << " ";
    if(node->right != nullptr)
        goRight(node->right);
}

void top_view(node *root) {
    if(root->left != nullptr)
        goLeft(root->left);
    
    if(root->right != nullptr)
    	// by passing the root as the argument (instead of root.right), we ensure it's printed by goRight
        goRight(root);
}

/*
void top_view(node *root){
    deque<node*> dq;
    node *aux = root;
    while (aux != nullptr){
        dq.push_front(aux);
        aux = aux->left;
    }
    aux = root->right;
    while (aux != nullptr){
        dq.push_back(aux);
        aux = aux->right;
    }
    for(auto i : dq) cout << i->data << " ";    
}
*/