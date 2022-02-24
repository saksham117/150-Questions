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
    
    void helper(TreeNode* root, int level, int* max_level, vector<int> & ans) 
    { 
    // Base Case 
    if (root == NULL) 
        return; 
  
    // If this is the first node of its level 
    if (*max_level < level) { 
        ans.push_back(root->val); 
        *max_level = level; 
    } 
  
    // Recur for left and right subtrees 
    helper(root->right, level + 1, max_level, ans);
    helper(root->left, level + 1, max_level, ans); 
     
    }
    
    
    vector<int> rightSideView(TreeNode* root) {
        
    
    int level = 1;
    int max_level = 0;
    vector<int> ans;
        
    helper(root, level, &max_level, ans);
    
    return ans;
        
    }
    
};