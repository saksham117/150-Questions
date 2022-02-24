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
    // 2 stack appraoch
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> output;

        if(root == NULL){
            return output;
        }

        stack<TreeNode*> st1;
        stack<TreeNode*> st2;

        // intially just push the root
        st1.push(root);

        // repeat while st1 is not empty
        while(!st1.empty()){

            TreeNode *node = st1.top();
            st1.pop();
            // push top of st1 in st2 and pop it from st1
            st2.push(node);

            // push left of st1 and then right of st1 in st1 itself
            if(node->left){
                st1.push(node->left);
            }

            if(node->right){
                st1.push(node->right);
            }
        }

        // st2 containes the postorder traversal order
        while(!st2.empty()){
            output.push_back(st2.top()->val);
            st2.pop();
        }

        return output;

    }
};