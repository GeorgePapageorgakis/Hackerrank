/*
Given a pointer to the root of the binary search tree and two values v1 and v2. 
Return the lowest common ancestor (LCA) of v1 and v2 in the binary search tree.

Sample Input:
         4
       /   \
      2     7
     / \   /
    1   3 6

	v1=1 and v2=7.

Sample Output:}
	LCA of 1 and 7 is 4 (which is the root). 

Node is defined as:
typedef struct node{
   int data;
   node * left;
   node * right;
}node;

*/
//It is guaranteed that v1 and v2 are present in the tree. 
//we assume v1 < v2
node * lca(node * root, const int& v1, const int& v2){
    //Its BST so either left or right else found
    //if both are greater than current node then lca is right
    if(root->data < v1 && root->data < v2){
        return lca(root->right, v1, v2);
    }
    //f both are less than current node then lca is left
    if(root->data > v1 && root->data > v2){
        return lca(root->left, v1, v2);
    }

    //Else solution already found
    return root;
}