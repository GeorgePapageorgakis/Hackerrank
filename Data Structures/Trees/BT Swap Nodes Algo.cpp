/*
Swapping: Swapping subtrees of a node means that if initially node has left subtree L and right subtree R, then after swapping left subtree will be R and right subtree L.

Eg. In the following tree, we swap children of node 1.
                                Depth
    1               1            [1]
   / \             / \
  2   3     ->    3   2          [2]
   \   \           \   \
    4   5           5   4        [3]

11
2 3
4 -1
5 -1
6 -1
7 8
-1 9
-1 -1
10 11
-1 -1
-1 -1
-1 -1
2
2
4
Mapped tree on vector:
													 _________________
				  ______________				  __|___________   |  |
_______ 	_____|__________  | |		 ________|__|__	__   |	|  |  |
|	 | |	|	 |		 |  | | |		|		 |	|  |  |	 |	|  |  |
1    2 3    4 -1 5 -1    6 -1 7 8    -1 9 -1 -1 10 11 -1 -1 -1 -1 -1 -1 
	 |_|____|_|  |  |	 |____|_|_____|_|  |  |  |  |
	   |_________|__|	 	  |_|__________|__|  |  |
							    |________________|__|						
swap:								
				    ___________
_______ 	   ____|_______  | |
|	 | |	  |	   |	|  | | |
1    2 3   -1 4 -1 5    6 -1 7 8    -1 9 -1 -1 10 11 -1 -1 -1 -1 -1 -1 
	 |_|____|_|  | |	|____|_|_____|_|  |  |  |  |
	   |_________|_|	 	 |_|__________|__|  |  |
							   |________________|__|

         1                     1                          1             
        / \                   / \                        / \            
       /   \                 /   \                      /   \           
      2     3    [s]        2     3                    2     3          
     /      /                \     \                    \     \         
    /      /                  \     \                    \     \        
   4      5          ->        4     5          ->        4     5       
  /      / \                  /     / \                  /     / \      
 /      /   \                /     /   \                /     /   \     
6      7     8   [s]        6     7     8   [s]        6     7     8
 \          / \            /           / \              \         / \   
  \        /   \          /           /   \              \       /   \  
   9      10   11        9           11   10              9     10   11 

2 9 6 4 1 3 7 5 11 8 10
2 6 9 4 1 3 7 5 10 8 11		
*/
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct node{
	int key;
	node *left;
	node *right;
	node(int i):key(i),left(nullptr),right(nullptr){};
};

//In Order tree traversal printing
void inOrder(node *root) {
    if (root == nullptr) return;
    inOrder(root->left);    
    cout << root->key << ' ';
    inOrder(root->right);  
	return;
}

//Deallocate Binary Tree
void btDestroyTree(node *leaf){
	if(leaf!=NULL){
		btDestroyTree(leaf->left);
		btDestroyTree(leaf->right);
		delete leaf;
	}
}

/* Compute the "maxDepth" of a tree -- the number of 
    nodes along the longest path from the root node 
    down to the farthest leaf node.*/
int maxDepth(struct node* node){
   if (node==NULL) 
       return 0;
   else {
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node->left);
       int rDepth = maxDepth(node->right);

       /* use the larger one */
       if (lDepth > rDepth) 
           return(lDepth+1);
       else return(rDepth+1);
   }
} 

/**
 * @param: 
 * node - node being visited
 * clevel - current level
 * rlevel - requested level
 * result - result queue
 * @return: Store every node of a queried level in a queue and return the queue
 */
void findLevelNodes(node *n, int clevel, int rlevel, queue<node*>& result) {
    if (clevel == rlevel)
        result.push(n);
    else {
        if (n->left != nullptr)
            findLevelNodes (n->left, clevel + 1, rlevel, result);
        if (n->right != nullptr)
            findLevelNodes (n->right, clevel + 1, rlevel, result);
    }
    return;
}

/**
	Perform swap operations no children of given level
*/
void btSwap(node *root, int level){
    //get all nodes on queried level
    queue<node*> lvlQueue;
    findLevelNodes(root, 1, level, lvlQueue);
    //perform swap for every node in queue
    while (lvlQueue.size()){
        //cout << "node to swap: " << lvlQueue.front()->key << endl;
        node *aux = lvlQueue.front()->left;
        lvlQueue.front()->left = lvlQueue.front()->right;
        lvlQueue.front()->right = aux;
        lvlQueue.pop();
    }
}

int main(void) {
    unsigned int n,t;
	//for mapping BT nodes on vector
	vector<node*> bt;
	vector<int> swapQueries;
	
	//get nodes and map them on vector
    cin >> n;
    bt.reserve(2*n+1);
    //push root
    bt.push_back(new node(1));
    for (unsigned i = 0; i < n; ++i) {
        int k, z;
        cin >> k >> z;
        bt.push_back(new node(k));
        bt.push_back(new node(z));
    }
    
	//assign node* pointers and map tree on vector
	int root = 0, child = 0;
	do{
		if (bt[root]->key != -1){
            ++child;
            if ( (child < bt.size()) && (bt[child]->key != -1) ){
                bt[root]->left = bt[child];
                //cout << "bt[" << root << "]->left = " << bt[root]->left << ", ";
            }
            ++child;
            if ( (child < bt.size()) && (bt[child]->key != -1) ){
                bt[root]->right = bt[child];
                //cout << "bt[" << root << "]->right = " << bt[root]->left << " ";
            }
        }
        ++root;
	}while((child < bt.size()) && (root<child+1));
       
    //get swap queries
    cin >> t;
    for (unsigned i = 0; i < t; ++i) {
        int k; cin >> k;
		swapQueries.push_back(k);
    }

    //Swap operation: Given a tree and a integer, K, we have to swap 
    //the subtrees of all the nodes who are at depth h, where h ε [K, 2K, 3K,...].
	for (int i = 0; i < t; ++i) {
        //find max level of current binary tree
        int k=1;
		while (k*swapQueries[i] < maxDepth(bt[0])){
            //perform swaps of all nodes at given level
			btSwap(bt[0], k*swapQueries[i]);
            ++k;
        }
        //In Order print
        inOrder(bt[0]); cout << endl;
    }
    
    //deallocate tree
    btDestroyTree(bt[0]);
    //bt.erase (bt.begin(),bt.end());
    return 0;
}