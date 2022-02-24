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


// The level-order traversal is the most time-efficient solution for this problem since we only go as deep as the 
// first potential cousin. The memory complexity is O(n/2) to accommodate the longest level, vs. 
// O(h) for recursive solutions, where h is the height of the tree (could be n in the worst case).

// We use queue q to iterate through the current level nodes and populate their children into q1. 
// We also insert nullptr into q1 after inserting each node's children (to separate siblings froum cousins).

// If we find a node with value x or y, we have one potential cousin. If we find another 
// potential cousin, we return true if they are not siblings (nullptr sets siblings to false). 
// If we finished the level with just one potential cousin, we stop and return false.

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        
    }
};

// https://leetcode.com/problems/cousins-in-binary-tree/discuss/238624/C%2B%2B-level-order-traversal