// https://leetcode.com/problems/count-complete-tree-nodes/
// 1) We are given a complete binary tree

// Given the root of a complete binary tree, return the number of the nodes in the tree.

// According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, 
// and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

// Design an algorithm that runs in less than O(n) time complexity.

// It is fairly simple to do it in O(N) time
// Just traverse the complete tree
// Space complexity of such a solution would be O(H), where H at worst would be logN(since it is a complete binary tree)

// However the whoe crux lies in solving it in less than O(N)

// Now lets explore the solution
// Had it been a perfect tree (all leaf nodes at same level and each node has 2 children)
// then we could calcualte height in O(N) or O(Logn) in our case as height cannot exceed logn (height = h)
// then number of nodes will be 2^h - 1 
// for height = 3, nodes are 2^3 -1 = 7

// So now we will see if we can extend this height property on any general complete tree 

// So algo is to find height of every subtree 
// So at every node I will try to find left height Note: We are not finding the height of left subtree
// we are finding left height
// I will find height of right height
// if they are same, answer is simply 2^h -1

// if not call recursivelhy for 1 + func(left)  func(right)


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
#include<unordered_set>
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
    int findLeftHeight(TreeNode* root){
        
        int height = 0;
        while(root){
            height++;
            root = root->left;
        }
        
        return height;
    }
    
    int findRightHeight(TreeNode* root){
        
        int height = 0;
        while(root){
            height++;
            root = root->right;
        }
        
        return height;
    }
    
    int countNodes(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        
        int leftHeight = findLeftHeight(root);
        int rightHeight = findRightHeight(root);
        
        if(leftHeight == rightHeight){
            return (1 << leftHeight) - 1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// Time Complexity = O(logn^2) (logn whole square)
// first logn is coz we are not traveeling more than logn Nodes, as it is complete binary tree
// and one half will be covered by the formula on line 91 directly

// the second logn is the call to the findHeight function(we travel logn nodes at max)

// Space complexity: O(logn) the recursive stack space
