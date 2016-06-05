/*
You have an empty Stack sequence, and given queries is one of these three types:
	1 x  -Push the element x into the stack.
	2    -Delete the element present at the top of the stack.
	3    -Print the maximum element in the stack.
*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <climits>
#include <string>
#include <sstream>
using namespace std;

class stack_size_error : public std::length_error {
    public:
        explicit stack_size_error(const std::string &msg): std::length_error(msg){}
};

class stack_bad_alloc : public std::bad_alloc {
    public:
        explicit stack_bad_alloc(void): std::bad_alloc(){}
};

class stack_overflow : public std::logic_error {
    public:
        explicit stack_overflow(const std::string &msg): std::logic_error(msg){}
};

class stack_empty : public std::logic_error {
    public:
        explicit stack_empty(const std::string &msg): std::logic_error(msg) {}
};

class Stack {
    private:
        int maxElem;
        vector<int> stackstore;
        unsigned int stacksize;
        unsigned int SP;
    public:
        Stack(unsigned int size = 65536)throw(stack_size_error, stack_bad_alloc);
        ~Stack();
        void push(int value)throw(stack_overflow);
        void pop(void)throw(stack_empty);
        int max(void)throw(stack_empty);
};
Stack::Stack(unsigned int size) throw(stack_size_error, stack_bad_alloc){ 
	if(size <= 0)
		throw stack_size_error("size must be >= 0");
    stackstore.resize(size);
	stacksize = size;
    maxElem = INT_MIN;
	SP = 0;
}
Stack::~Stack(void) {
	// clear stackstore by reallocating
	vector<int>().swap(stackstore);
}
void Stack::push(int value) throw(stack_overflow){
	if(SP == stacksize)
		throw stack_overflow("stack size exceeded");
	stackstore[SP++] = value;
    if ((maxElem != INT_MIN) && (value > maxElem))
        maxElem = value;
}
void Stack::pop(void) throw(stack_empty){ 
	if(SP == 0)
		throw stack_empty("stack is empty");
    if (stackstore[--SP] == maxElem)
        maxElem = INT_MIN;
}
int Stack::max(void) throw(stack_empty){
    if(SP == 0)
		throw stack_empty("stack is empty");
    if (maxElem == INT_MIN) 
        maxElem = *max_element(stackstore.begin(), stackstore.begin()+SP);
    return maxElem;
}


int main() {
    int n, size;
    string s;
    
    getline(cin, s);        
    stringstream ss(s);
    ss >> n;
    if (n < 10)
        size = 16;
    else if (n < 100)
        size = 128;
    else if (n < 1000)
        size = 1024;
    else if (n < 10000)
        size = 16384;
    else
        size = 65536;
        
    Stack stk(size);
	for (int i=0; i<n; ++i){
		int c, k;
        getline(cin, s);
        stringstream ss(s);
        if(!s.find(" ")) ss >> c;
        else ss >> c >> k;
        
        if (c == 1)
            stk.push(k);
		else if(c == 2)
            stk.pop();
		else if(c == 3)
            cout << stk.max() << endl;
	}
    return 0;
}
