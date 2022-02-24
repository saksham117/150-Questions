// Tries are basically used when we have to store a word, or say search for a word, does the word start with this prefix

// So lets discuss tries, by first looking at how to insert vsarious owrds and keep a track of them 
// lets say words are apple, apps, apxl, bac, bat

// So a trie will be implemented as a class
// the class will look like 

class Trie{
    int a[26]; // this array of size 26 represents, what all children of that node are present
    bool flag; // intialized as false
};

// children of a node will be lowercase english letters a-z. 

// So a trie will always have a root at the top.

// Now the task given to root is to insert word apple
// You will go to root and say, hey is a present? Since array is currently empty you will say no
// So you will create a Trie object, which will represent character a, and then store its address in array[0] of root 

// siminlary to store p of apple, you will go to trie structure a, in its array create a new trie for p and in the 
// array of a trie object, fill in the address of this new trie object

// after adding e, we will make it point to another trie object, in which the trie objects flag will be true
// this will signify that the word is complete, and e is the location where it ends 

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<unordered_set>

using namespace std;




// this is the code I wrote whi;e revising
// fully logical
// no faltu ke calls to any helper functions
// just plain simple for loop and condition checking

class TrieNode{
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode(){
        isEnd = false;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
};


class Trie {
public:
    
    TrieNode* root;
    
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        
        TrieNode* node = root;
        int n = word.length();
        
        for(int i = 0; i < n; i++){
            
            if(node->children[word[i] - 'a'] == NULL){
                TrieNode* newNode = new TrieNode();
                node->children[word[i] - 'a'] = newNode;
            }
            
            node = node->children[word[i] - 'a'];
        }
        
        node->isEnd = true;
        
    }
    
    bool search(string word) {
        TrieNode* node = root;
        int n = word.length();
        
        for(int i = 0; i < n; i++){
            if(node->children[word[i] - 'a'] == NULL){
                return false;
            }

            node = node->children[word[i] - 'a'];
        }
        
        if(node->isEnd){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        int n = prefix.length();
        
        for(int i = 0; i < n; i++){
            if(node->children[prefix[i] - 'a'] == NULL){
                return false;
            }

            node = node->children[prefix[i] - 'a'];
        }
        
       return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


// we will use this struct in class Trie, where every node of class Trie will be of this type
// so we have 2 variables, and 5 helper functions
// the role of these helper function will become clear once we implement the 3 functions of insert, search and startswith


// #### My learnings: ####
// - helper function of struct node should be written thoughtfuuly
//  - always use node->contains, node->put, not directly get and put 

struct Node {
    Node *links[26]; // array of size 26, where each element is a pointer to an address of object type Node itself
    bool flag = false; // a flag which is set to false initially. flag == true indicates, the word has ended 
    
    bool containsKey(char ch) { // helper function to check if that node of trie already has that character or not
        return (links[ch - 'a'] != NULL); 
    }

    Node* get(char ch) { // if it does contain, then return the address of that character
        return links[ch-'a']; 
    }

    void put(char ch, Node* node) { // if character is not present, then put it inside the Node* links array
        links[ch-'a'] = node; 
    }

    void setEnd() { // to set the end of word
        flag = true; 
    }

    bool isEnd() { // to see if word has ended
        return flag; 
    }
}; 


class Trie {
    private: Node *root; // root is a priavte member
    
    public:
    /** Initialize your data structure here. */
    // root is always going to be there and will always point to start of all alphabets in out dictionary
    Trie() {
        root = new Node(); 
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {

        Node *node = root; // start of with the root

        // iterate over the length of the word
        for(int i = 0;i<word.size();i++) {
            // if that letter is not present
            // add it
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node()); 
            }

            // now get the node having that alphabet at index i so using this we can check for the next index
            node = node->get(word[i]); 
        }
        // after word is fininshed, set flag to true
        node->setEnd(); 
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *node = root;  // start of with the root

        // iterate over the word
        for(int i = 0;i<word.size();i++) {
            // if at any moment, that letter is not present, return false
            if(!node->containsKey(word[i])) {
                return false; 
            }
            // find the node address having that letter
            node = node->get(word[i]); 
        }
        // if we are at end of word, return true, else false
        if(node->isEnd()) {
            return true; 
        }
        return false; 
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        // same as search
        // only difference is that we d not check if the word ends or not
        // as we are only interested in the prefix
        Node *node = root; 
        for(int i = 0;i<prefix.size();i++) {
            if(!node->containsKey(prefix[i])) {
                return false; 
            }
            node = node->get(prefix[i]); 
        }
        return true; 
    }
};