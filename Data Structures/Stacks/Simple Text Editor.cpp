/*
In this challenge, you must implement a simple text editor. Initially, your editor contains an empty string, S. You must perform Q operations of the following 4 types:

   1. append(W) - Append string W to the end of S.
   2. delete(k) - Delete the last k characters of S.
   3. print(k) - Print the k-th character of S.
   4. undo() - Undo the last (not previously undone) operation of type 1 or 2, reverting S to the state it was in prior to that operation.
	
*/
#include <sstream>
#include <stack>
#include <string>
#include <iostream>
using namespace std;

class simpleTextEditor{
    private:
        int op, k;
        string s;
		stack<string> undoStack;
    public:
        simpleTextEditor(): op(0), k(0), s(""){}

        // Append string W to the end of S.
        void append(string& W){
            this->undoStack.push(this->s);
            this->s += W;
        }
    
        //Delete the last k characters of S.
        void deletechar(int& k){
            this->undoStack.push(this->s);
            this->s = this->s.substr(0, this->s.size()-k);
        }

        //Print the k-th character of S.
        void print(int& k){
            cout << this->s.at(k-1) << endl;
        }
    
        //Undo the last (not previously undone) operation of type 1 or 2, 
        //reverting S to the state it was in prior to that operation.
        void undo(){
            this->s = this->undoStack.top();
            this->undoStack.pop();
        }
};



int main() {
	simpleTextEditor STE;
    string s, txt;
    int n, k, op;
    
    getline(cin, s);
    stringstream ss(s);
    ss >> n;
    ss.clear();
    
    for(unsigned i=0; i<n; ++i){
        getline(cin, s);
        ss.str(s);        
        if(!s.find(" ")) ss >> op;  //if operation is 4 (undo)
        else ss >> op >> txt;


        switch (op){
            case 1:
                STE.append(txt);
                break;
            case 2:           
                ss.clear(); ss.str(txt);
                ss >> k;
                STE.deletechar(k);
                break;
            case 3:
                ss.clear(); ss.str(txt);
                ss >> k;
                STE.print(k);
                break;
            case 4:
                STE.undo();
                break;
            default:
                break;
        }
        txt = "";
        ss.clear();
        ss.str(txt);
    }   
    return 0;
}
