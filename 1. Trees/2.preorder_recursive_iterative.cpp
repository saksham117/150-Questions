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


class Solution {
public:
    stack<TreeNode*> s;
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> output;
        
        if(root == NULL)
        {
            return output;
        }

        s.push(root);


        while(!s.empty()){
            TreeNode * node = s.top();
            s.pop();
            output.push_back(node->val);

            if(node->right){
                s.push(node->right);
            }

            if(node->left){
                s.push(node->left);
            }
        }

        return output;
    }
};