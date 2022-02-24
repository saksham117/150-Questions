#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
#include<stack>


using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive I Know
// Iterative I coded myself
// Just had a hint ki stack can be used
// but all code is my thinking

class Solution {
public:
    stack<TreeNode*> s;
    // helper function to push all the left children of node into stack
    void helper(TreeNode* root)
    {
        if(root == NULL){
            return;
        }

        if(root->left)
        {
            s.push(root->left);
        }

        helper(root->left);
    }

    // first added root as well as its left children
    // then poped them one by one and then called helper function on the popped nodes->right
    // also inserted popped->right to stack before calling helper function
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        
        if(root == NULL)
        {
            return output;
        }

        s.push(root);
        helper(root);

        while(!s.empty()){
            TreeNode * node = s.top();
            s.pop();
            output.push_back(node->val);

            if(node->right){
                s.push(node->right);
                helper(node->right);
            }
        }

        return output;
    }
};
