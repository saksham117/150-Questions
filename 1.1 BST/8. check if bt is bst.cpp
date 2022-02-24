#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

// Solution https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
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
      bool helper(TreeNode* node, long int minimum, long int maximum){

        if(node == NULL){
            return true;
        }

        // if node value is smaller than minimum or node value is greater than maximum
        if(node-> val < minimum || node->val > maximum){
            return false;
        }

        
        // else check for other nodes with narrower bounds
        // adding -1 and + 1 to check for duplicate nodes and return false if they exist
        return helper(node->left, minimum, (long)(node->val) - 1) && helper(node->right, (long)(node->val) + 1, maximum);


    }

    bool isValidBST(TreeNode* root) {
        long  minimum = (long)(INT_MIN) - 1;
        long  maximum = (long)(INT_MAX) + 1;
        return helper(root, minimum, maximum);
    }
};

// Solution 2
// (Using In-Order Traversal) 
// Thanks to LJW489 for suggesting this method. 
// 1) Do In-Order Traversal of the given tree and store the result in a temp array. 
// 2) This method assumes that there are no duplicate values in the tree
// 3) Check if the temp array is sorted in ascending order, if it is, then the tree is BST.
// Time Complexity: O(n)
// We can avoid the use of a Auxiliary Array. While doing In-Order traversal, we can keep track of previously visited node. 
// If the value of the currently visited node is less than the previous value, then tree is not BST. 
