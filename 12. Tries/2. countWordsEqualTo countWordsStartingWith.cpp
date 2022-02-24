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


struct Node {
    // this remains the same
    Node *links[26]; 

    // these 2 are added
    int cntEndWith = 0;
    int cntPrefix = 0; 
    
    // these 3 funcs are same as before
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL); 
    }
    Node* get(char ch) {
        return links[ch-'a']; 
    }
    void put(char ch, Node* node) {
        links[ch-'a'] = node; 
    }
    
    // both will be used while inserting word
    // to increase word count
    void increaseEnd() {
        cntEndWith++;  
    }
    // to increase prefix count
    void increasePrefix() {
        cntPrefix++; 
    }

    // helpful while erasing
    void deleteEnd() {
        cntEndWith--; 
    }
    void reducePrefix() {
        cntPrefix--; 
    }

    // return how many word or many prefixes
    // will be directly used in functions counWordwith, countStartsWith
    int getEnd() {
        return cntEndWith; 
    }
    int getPrefix() {
        return cntPrefix; 
    }
}; 

class Trie{
private: Node *root; 
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node(); 
    }

    // till here it is same
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        for(int i = 0;i<word.length();i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node()); 
            }
            node = node->get(word[i]); 
            node->increasePrefix(); // this is added
        }
        node->increaseEnd(); // this is added
    }
    
    // go till end and if word found, return number of occurences
    // else return 0
    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i = 0;i<word.length();i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
            }
            else {
                return 0; 
            }  
        }
        return node->getEnd(); 
    }

    // same as prev but uses different variables and data members 
    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i = 0;i<word.length();i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
            }
            else {
                return 0; 
            }  
        }
        return node->getPrefix(); 
    }

    // just reduce word count and prefix count
    // do not physicaaly delete the notes
    // this is imp as more than one occurence of a word can be there
    void erase(string &word){
        Node* node = root;
        for(int i = 0;i<word.length();i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
                node->reducePrefix(); 
            }
            else {
                return;
            }
        }
        node->deleteEnd(); 
    }
};