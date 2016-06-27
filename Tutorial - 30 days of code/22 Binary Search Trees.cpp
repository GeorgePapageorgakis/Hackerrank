#include <iostream>
#include <cstddef>
using namespace std;

	
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data=d;
            left=right=NULL;
        }
};


class Solution{
    public:
  		Node* insert(Node* root, int data){
            if(root==NULL){
                return new Node(data);
            }
            else{
                Node* cur;
                if(data<=root->data){
                    cur=insert(root->left,data);
                    root->left=cur;
                }
                else{
                   cur=insert(root->right,data);
                   root->right=cur;
                 }
           return root;
           }
        }
		
		/*
        The height of a tree is the length of the path from the root to the deepest node in the tree. 
        A (rooted) tree with only 1 node (the root) has a height of zero." - If there is 
        no node you want to return -1 not 0 because you are adding 1 at the end so if there 
        isn't a node you return -1 which cancels out the +1.        
        */
        int getHeight(Node* root) {
            if (root == NULL) 
                return -1;
            int lefth = getHeight(root->left);
            int righth = getHeight(root->right);
            return 1 + (lefth>righth ? lefth : righth);
        }
};//End of Solution


int main(){
    Solution myTree;
    Node* root=NULL;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        root= myTree.insert(root,data);
    }
    int height= myTree.getHeight(root);
    cout<<height;
    return 0;
}
 