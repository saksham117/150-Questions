// we will use the concept of finding maximum height of a binary tree
// and maximum width of a binary tree 

// for any node which is part of the path
// the max sum along it will be maxSumToLeft + Node->Val +maxSumToRight

// good question
// yeh aise hi hoga
// overtime samjh aayga
// revision required

// dry run karo, samjh aa jaayega
// Note: If from left subtrre or roght subtree, we are getting a negative path sum
// consider them as zero and not a negative number
// useful in case like

//       15
//      / \ 
//    10  20
//        / \ 
//     -30  -15         
// 


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
    int maxPathSum(TreeNode* root) {
       int maxi = INT_MIN; 
        maxPathDown(root, maxi); 
        return maxi;  
    }
    
    int maxPathDown(TreeNode* node, int &maxi) {
        if (node == NULL) return 0;
        int left = max(0, maxPathDown(node->left, maxi)); // max of zeor and func call ensure we do not take a negative path 
        // sum from left or right
        int right = max(0, maxPathDown(node->right, maxi));
        maxi = max(maxi, left + right + node->val);
        return max(left, right) + node->val;
    }
};

// To summarize:

// Initialize a maxi variable to store our final answer.
// Do a simple tree traversal. At each node, find  recursively its leftMaxPath and its rightMaxPath.
// Calculate the maxPath through the node as val + (leftMaxPath + rightMaxPath) and update maxi accordingly.
// Return the maxPath when node is not the curving point as val + max(leftMaxPath, rightMaxPath).

// see editorial
// there diagram explains why
// i also took some test cases and understood
