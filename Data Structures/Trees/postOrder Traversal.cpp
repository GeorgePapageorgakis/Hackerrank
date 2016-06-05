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
	1 4 5 6 2 3 
*/
void postOrder(node *root) {
    if (root == nullptr) return;   
    postOrder(root->left);
    postOrder(root->right);  
    cout << root->data << ' ';
	return;
}
