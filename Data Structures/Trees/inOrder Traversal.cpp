/* you only have to complete the function given below.  
Node is defined as:

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
	1 5 4 3 6 2 
*/
void inOrder(node *root) {
    if (root == nullptr) return;
    inOrder(root->left);    
    cout << root->data << ' ';
    inOrder(root->right);  
	return;
}
