#include <iostream>
#include <list>
#include <string>
#include <exception>
#include <stdexcept>
using namespace std;

/*
A palindrome is a word, phrase, number, or other sequence of characters which reads the same backwards and forwards. Can you determine if a given string, s, is a palindrome?
*/

class solution_bad_alloc : public std::bad_alloc {
    public:
        explicit solution_bad_alloc(void) : std::bad_alloc() {};
};

class solution_empty : public std::logic_error {
    public:
        explicit solution_empty(const std::string &msg) : std::logic_error(msg) {};
};

class Solution {
    private:
        list<char> stack;
        list<char> queue;
    public:
        //method that pushes a character onto a stack instance variable.
        void pushCharacter(char ch){
            stack.push_back(ch);
            if(stack.empty())
		        throw solution_bad_alloc();
            return;
        }
        //method that enqueues a character in the queue instance variable.
        void enqueueCharacter(char ch){
            queue.push_back(ch);
            if(queue.empty())
                throw solution_bad_alloc();
            return;
        }
        //method that pops and returns the character at the top of the stack instance variable.
        char popCharacter(void) throw(solution_empty){
            if(stack.empty())
		        throw solution_empty("stack is empty");
            char c = stack.back();
            stack.pop_back();
            return c;
        }
        //method that dequeues and returns the first character in the queue instance variable.
        char dequeueCharacter(void) throw(solution_empty){
            if(queue.empty())
		        throw solution_empty("queue is empty");
            char c = queue.front();
            queue.pop_front();
            return c;
        }
};

int main() {
    // read the string s.
    string s;
    getline(cin, s);
    
  	// create the Solution class object p.
    Solution obj;
    
    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    
    bool isPalindrome = true;
    
    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;
            
            break;
        }
    }
    
    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }
    
    return 0;
}
