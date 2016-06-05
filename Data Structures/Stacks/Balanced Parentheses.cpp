/*
Given a sequence consisting of parentheses, determine whether the expression is balanced. A sequence of parentheses is balanced if every open parentheses can be paired uniquely with a closed parentheses that occurs after the former. Also, the interval between them must be balanced. You will be given three types of parentheses: (, {, and [.

{[()]} - This is a balanced parentheses.
{[(])} - This is not a balanced parentheses.

Sample Input:
3
{[()]}
{[(])}
{{[[(())]]}}

Sample Output:
YES
NO
YES
*/
#include <sstream>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;


bool isBalanced(string& parenStr){
    stack<char> sChars;
    
    if ( parenStr.size()% 2 != 0 )
        return false;
    
    for(int i=0; i<parenStr.size(); ++i){
        //push only if its opening parentheses types
        if ((parenStr[i] == '(') || (parenStr[i] == '[') || (parenStr[i] == '{'))
            sChars.push(parenStr[i]);
        //else check for each seperate case
        else if (!sChars.empty()){
            if (parenStr[i] != ')'){
                if (sChars.top() == '(')
                    return false;
            }
            else if (parenStr[i] != ']'){
                if (sChars.top() == '[')
                    return false;
            }
            else if (parenStr[i] != '}'){
                if (sChars.top() == '{')
                    return false;
            }
            sChars.pop();
        }
        else if (sChars.empty())
            return false;
    }
    //in case for example of [(({ 
    if (sChars.empty())
        return true;
    return false;
}


int main() {
    vector<string> vs;
    string s;
    int n;

    getline(cin, s);
    stringstream num(s);
    num >> n;
    vs.resize(n);
    for(unsigned i=0; i<n; ++i){
        getline(cin, vs[i]);
    }
    
    for(unsigned i=0; i<n; ++i){
        cout << (isBalanced(vs[i]) ? "YES" : "NO") << endl;
    }
    return 0;
}
