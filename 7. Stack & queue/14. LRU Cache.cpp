// task is to desgin this in O(1) complexity
// O(n) to arrays and all de denge 

// So we will be using a hashmap and a doubly linked linkedlist 
// define the capacity

// if size is less than capacity
    // on put operation, just insert the element just behind the head 
    // at the same time, in the map, add the key and its value as the address of this node
// else 
    // delete the last node from the linked list
    // delete it from the hashmap 
    // add new node to start of ll
    // make its entry into the hashmap


// if on get, key does not exist in the map
    // then we return -1
// else 
    // we return the key
    // then in ll delete that node and insert this node again just behind the head 
    // also since we deleted the node and added a new node behind head, so we also update the address

// if on put, the key already exists
// delete the prev occurnce from both dll and map
// then add it to front of ll and make an entry into hashmap 
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
#include<map>

using namespace std;


class LRUCache {
public:
    // NODE FOR OUR DOUBLY LINKED LIST
    class node{
        public:
            int key;
            int val;
            node* next; 
            node* prev;

            node(int key, int val){
                this->key = key;
                this->val = val;
            }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    int cap; // dentoing the capacity 
    unordered_map<int, node*> m; // unordered hashmap 

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node* newNode){
        // stroing current node at start in variable temp
        node* temp = head->next; 
        // setting links for new node
        newNode->next = temp; 
        newNode->prev = head; 
        // updating links for head and temp
        head->next = newNode;
        temp->prev = newNode; 
    }

    // here we directly did not interact with tail, coz in this deleteion in some case will happen from tail, in other 
    // scenarios from other 
    // locations. That is why we gave a general solution
    // we purposely just changed the links and not dleted the actual node
    // coz in get function, we are utilizing the same node itself.
    void deleteNode(node* delNode){
        // firstly gathering next and prev nodes of the node to be deleted
        node* delPrev = delNode->prev;
        node* delNext = delNode->next; 

        // then creating the relevant linking
        delPrev->next = delNext;
        delNext->prev = delPrev;

    }
    
    int get(int key) {

        // if the key exists
        if(m.find(key) != m.end()){
            
            node* resNode = m[key]; // get the address of the node
            int value = resNode->val;  // get the value associated with it

            m.erase(key); // delete it from map as its address will be updated 
            deleteNode(resNode); // deleted the node

            addNode(resNode); // added it to start of ll
            m[key] = head->next; // updated its address

            return value;
        }

        return -1;
        
    }
    
    void put(int key, int value) {
        // if key already exisits
        // delete it from map and then delete it from ll
        if(m.find(key) != m.end()){
            node* exisitingNode = m[key];
            m.erase(key);
            deleteNode(exisitingNode);
        }

        // if capacity is reached delete the last element from map and ll
        if(m.size() == cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        // addnode to start of ll and also make an entry into map
        addNode(new node(key, value));
        m[key] = head->next;
    }
};