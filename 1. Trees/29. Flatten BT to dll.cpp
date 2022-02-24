// jsut use the concept of q 28
// also besides curr, mainatina a prev pointer
// so that it helps us to create links for the previous pointer for a given node
// https://www.codingninjas.com/codestudio/problems/893106?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
#include<stack>
#include<map>




// Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


// This function should return head to the DLL
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    
    void helper(Node* curr, Node*& prev){
        
        if(curr == NULL){
            return;
        }    
        
        helper(curr->right, prev);
        
        curr->right = prev;
        
        if(prev){
            prev->left = curr;
        }
        
        prev = curr;
        
        helper(curr->left, prev);
    }
    
    
    Node * bToDLL(Node *root)
    {
        // your code here
        Node* prev = NULL;
        Node* newHead = root;
        
        while(newHead->left != NULL){
            newHead = newHead->left;
        }
        
        helper(root, prev);
        return newHead;
    }
};