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


// note
// when updating indices
// calculate other indices (like postEnd and poststart) using postEnd 
// as that is what we know and acts as a pivot
class Solution {
public:

    TreeNode* helper(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& inMap){

        if(inStart > inEnd || postStart > postEnd){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = inMap[root->val];

        int numsRight = inEnd - inRoot;

        root->left = helper(inorder, inStart, inRoot - 1, postorder, postStart, postEnd - numsRight -1, inMap);
        root->right = helper(inorder, inRoot + 1, inEnd, postorder, postEnd - numsRight, postEnd - 1, inMap);

        return root;


    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map<int, int> inMap;
        
        for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        TreeNode* root = helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() -1, inMap);
        return root;

    }
};