// done earlier
// like in the after 14dec folder
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>


using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    pair<int, bool> helper(TreeNode *root){

        if(root == NULL)
        {
            pair<int,bool> temp = make_pair(0, true);
            return temp;
        }

        // no need to cover this case vaise
        if((root->left == NULL && root->right == NULL))
        {
            pair<int,bool> temp = make_pair(1, true);
            return temp;
        }

        pair<int, bool> left = helper(root->left);
        pair<int, bool> right = helper(root->right);

        pair<int, bool> node;

        node.first = max(left.first, right.first) + 1;
        bool balanced = abs(left.first - right.first) > 1 ? false : true;
        node.second = left.second && right.second && balanced;

        return node;
    }

    bool isBalanced(TreeNode* root) {

        pair<int, bool> ans = helper(root);
        return ans.second;
        
    }
};