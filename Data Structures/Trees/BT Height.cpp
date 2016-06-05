/*The tree node has data, left child and right child 
struct node{
    int data;
    node* left;
    node* right;
};

The height of a tree is the length of the path from the root to the deepest node in the tree. 
A (rooted) tree with only 1 node (the root) has a height of zero." - If there is 
no node you want to return -1 not 0 because you are adding 1 at the end so if there 
isn't a node you return -1 which cancels out the +1.        
*/
int height(node * root){
    if (root == NULL) 
        return -1;
    int lefth = height(root->left);
    int righth = height(root->right);
    return 1 + (lefth>righth ? lefth : righth);
}