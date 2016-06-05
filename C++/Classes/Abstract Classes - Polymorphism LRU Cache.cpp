/*
A cache is a component that stores data so future requests for that data can be served faster. The data stored in a cache might be the results of an earlier computation, or the duplicates of data stored elsewhere. A cache hit occurs when the requested data can be found in a cache, while a cache miss occurs when it cannot. Cache hits are served by reading data from the cache which is faster than recomputing a result or reading from a slower data store. Thus, the more requests that can be served from the cache, the faster the system performs.

One of the popular cache replacement policies is: "least recently used" (LRU). It discards the least recently used items first.
For example, if a cache with a capacity to store 5 keys has the following state(arranged from most recently used key to least recently used key) -
	
	5 3 2 1 4

If the next key comes as 1(which is a cache hit), then the cache state in the same order will be -

	1 5 3 2 4

If the next key comes as 6(which is a cache miss), then the cache state in the same order will be -

	6 1 5 3 2

Observe that 4 has been discarded because it was the least recently used key and since the capacity of cache is 5, it could not be retained in the cache any longer.
*/

/*
abstract base class Cache with member variables and functions:
	mp - Map the key to the node in the linked list
	cp - Capacity
	tail - Double linked list tail pointer
	head - Double linked list head pointer
	set() - Set/insert the value off the key, if present, otherwise add the key as the most recently used key. If the cache has reached its capacity, it should replace the least recently used key with a new key.
	get() - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1. Then make that key as the most recently used key.
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function
};

/*
Class LRUCache extends the class Cache and uses the member functions and variables to implement an LRU cache.
*/
class LRUCache : public Cache{
    private:
        void cacheUpdateHead(const int& key){
            Node* aux;
            //update only if key node is not already head
            if (head != mp[key]){
                aux = mp[key];      
                if (tail != aux){
                    aux->prev->next = aux->next;
                    aux->next->prev = aux->prev;
                }
                aux->next = head;
                head->prev = aux;
                head = aux;
            }
        }
    
        void cacheAddElement(const int& key, const int& val){
            Node* p = new Node(key, val);
            mp.insert(pair<int,Node*>(key, p));
            //if cache is empty
            if(head==nullptr){
                head = p;
                tail = p;                
            }
            else{
                head->prev = p;
                p->next = head;
                head = p;
            }
        }
    
        void cacheDeleteTail(){
           Node* aux = tail;
           mp.erase(tail->key);
           tail = aux->prev;
           tail->next = nullptr;
           delete aux;
       }
    
    public:
        LRUCache(int capacity){ head=nullptr; tail=nullptr; cp=capacity; }
        ~LRUCache(){ while (head){ auto node = head; head = head->next; delete node; }}
    
        void set(int key, int val){
            if (mp.count(key)){
                mp[key]->value = val;
                //update key's Node to be the head
                cacheUpdateHead(key);
            }
            else{
                //add new Node in cache
                cacheAddElement(key, val);
                if (mp.size() > cp){
                    //delete tail to maintain cache size
                    cacheDeleteTail();
                }      
            }
        }
        int get(int key){
            if (mp.count(key)){
                //update key's Node to be the head
                cacheUpdateHead(key);
                return mp[key]->value;
            }
            return -1;
        }
};


int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}