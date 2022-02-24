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
                
        for(int i = 0; i < root->children.size(); i++){
            
            helper(root->children[i], output);
        }
        
        
        output.push_back(root->val);

    }
    
    vector<int> postorder(Node* root) {
        vector<int> output;
        
        helper(root, output);
        return output;
    }
};

// iterative post order
vector<int> postorder(Node* root) {
    if(root==NULL) return {};
    vector<int> res;
    stack<Node*> stk;
    stk.push(root);
    while(!stk.empty())
    {
        Node* temp=stk.top();
        stk.pop();
        for(int i=0;i<temp->children.size();i++) stk.push(temp->children[i]);
        res.push_back(temp->val);
    }
    reverse(res.begin(), res.end());
    return res;
}