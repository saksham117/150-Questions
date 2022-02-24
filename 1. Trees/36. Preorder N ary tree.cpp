// Definition for a Node.
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
#include<unordered_set>
#include<stack>
#include<map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    void helper(Node* root, vector<int>& output){
        
        if(root == NULL){
            return;
        }
        
        output.push_back(root->val);
        
        for(int i = 0; i < root->children.size(); i++){
            
            helper(root->children[i], output);
        }
    }
    
    vector<int> preorder(Node* root) {
        
        vector<int> output;
        
        helper(root, output);
        return output;
    }
};

// Iterative Preorder
// https://leetcode.com/problems/n-ary-tree-preorder-traversal/discuss/149093/C%2B%2B-44ms-beats-100-both-iterative-and-recursive

// in iterative preorder in binary tree, we used to push right into stack and then left(in reverse order)
// so here, in the case of n-ary tree, we would iterate the children vector from right to left, that is from last element first and then
// first element, resulting in leftmost element being at the top of the stack 
// good ad clean approach
 