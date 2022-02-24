
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
#include<stack>
#include<map>

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
    int count = 0;

    void helper(TreeNode* root, int k, int& ans){

        if(root == NULL){
            return;
        }

        helper(root->left,k,ans);
        count += 1; 
        if(count == k){
            ans = root->val;
            return;
        }
        helper(root->right,k,ans);
        return;

    }

    
    int kthSmallest(TreeNode* root, int k) {

        int ans = -1;
        helper(root,k,ans);
        return ans;
        
    }
};