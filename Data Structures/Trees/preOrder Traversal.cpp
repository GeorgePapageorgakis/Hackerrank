/* you only have to complete the function given below.  
Node is defined as  

struct node{
    int data;
    node* left;
    node* right;
};
		3
	  /	  \
	 5	   2
    / \	  /
   1   4 6   
Input:
	6
	3 5 2 1 4 6
Output:
	3 5 1 4 2 6 
*/
void preOrder(node *root) {
    if (root == nullptr) return;
    cout << root->data << ' ';
    preOrder(root->left);
    preOrder(root->right);
	return;
}