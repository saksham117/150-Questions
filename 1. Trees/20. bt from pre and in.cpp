// Can you construct a unique binary tree with following
// 1) Pre and Post?
// No 
// take a counterexample
// say in [1,2,3] post [3,2,1]
//  two trees are

//          1             and    1
//         /                     /
//        2                     2
//       /                       \   
//      3                          3


// 2) In and Pre and In and Post will give unique trees

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
    // pass map by refernce
    // else TLE on leetcode
    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd,unordered_map<int,int>& inMap){

        // base case
        if(preStart > preEnd || inStart > inEnd){
            return NULL;
        }

        // creating the root node
        TreeNode* root = new TreeNode(preorder[preStart]);

        // finding index of root in inorder array from map
        int inRoot = inMap[root->val];

        int numsLeft = inRoot - inStart; // number of elements to the left of root in inorder array

        // how we are updating the indices will be clear when you take some examples
        root->left = helper(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
        root->right = helper(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

        return root;

    
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int,int> inMap;

        // filling the inorder within the map
        // only one timr O(N) work
        for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        } 

        TreeNode* root = helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);

        return root;
        
    }
};