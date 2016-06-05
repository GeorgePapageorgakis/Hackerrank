/* 
Huffman compression coding assigns variable length codewords to fixed length input characters based on their frequencies. More frequent characters are assigned shorter codewords and less frequent characters are assigned longer codewords. 
A Huffman tree is made for the input string and characters are decoded based on their position in the tree. We add a '0' to the codeword when we move left in the binary tree and a '1' when we move right in the binary tree. We assign codes to the leaf nodes which represent the input characters.

Sample Input:
         {ϕ,5}
      0 /     \ 1
     {ϕ,2}   {A,3}
    0/   \1
{B,1}  {C,1}  

	S="1001011"

Sample Output:
	ABACA

In Huffman coding, no code is prefix of any other code.

The structure of the node is

typedef struct node{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;
*/
void decode_huff(node * root,string s){
    node *aux = root;
    string::iterator it = s.begin();
   
    while(it!=s.end()){
        if (*it=='0'){
            if (aux->left != nullptr)
               aux = aux->left;
            
        }
        else if (*it=='1'){
            if (aux->right != nullptr)
                aux = aux->right;
        }
        if(aux->data != '\0'){
            cout << aux->data;
            aux = root;
        }
        ++it;
    } 
}