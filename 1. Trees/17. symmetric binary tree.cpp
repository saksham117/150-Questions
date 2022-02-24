// the tree forms a mirror of itself around tghe center or not 

//          1
//         / \ 
//        2   2
//      / \   / \ 
//     3   4 4   3
// 
//  Mirror image around the center, ir if we draw a line passing through the root 

// In a mirrored subtree, left will become right and right will become left
// So if in the left subtree, I traverse like this
// Root Left Right (preorder)

// Then in right subtree which is a mirror image
// This traversal Root Right Left should give the same nodes (coz of mirror property: lateral inversion)

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
    bool isSymmetricHelp(TreeNode* left, TreeNode* right){

        // if bith left and right are null then only return true
        // if either is null return false
        if(left == NULL || right == NULL){
            return left == right;
        }

        // theri values should also be equal
        if(left->val != right->val){
            return false;
        }

        // left subtree ka left == right subtree ka right
        // left subtree ka right == right subtree ka left
        // mirror property 
        return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);

    }
    // main function
    // if root == NULL
    // return true
    // else call the helper function where we compare left subtree and right subtree
    bool isSymmetric(TreeNode* root) {
        return root == NULL || isSymmetricHelp(root->left, root->right);
    }
};