// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

// Given the root of a binary tree, flatten the tree into a "linked list":

// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list 
// and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.

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

// You cannot / do not have to create a new LL. You have to rearrange these nodes itself.

// solution 1: go full right, then go left, then perform operation on root
// maintain a global prev pointer

class Solution {
    TreeNode* prev = NULL;
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return; 
        
        flatten(root->right); 
        flatten(root->left); 
        
        root->right = prev;
        root->left = NULL; 
        prev = root; 
    }
};
// TC - O(N) 
// SC - O(N) 


// iterative approach 
// I coded this approach, the next time I tried this question :)


// Iterative 
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return; 
        stack<TreeNode*> st; 
        st.push(root); 
        while(!st.empty()) {
            TreeNode* cur = st.top(); 
            st.pop(); 
            
            if(cur->right != NULL) {
                st.push(cur->right); 
            }
            if(cur->left != NULL) {
                st.push(cur->left); 
            }
            if(!st.empty()) {
                cur->right = st.top(); 
            }
            cur->left = NULL;
        }
        
    }
};

// TC - O(N) 
// SC - O(N)



// Using Morris Traversal
// whatever is the righmost node in the left subtree of root
// connecr its right to root->right

// and then connect root->right to root->left
// TC - O(N) 
// SC - O(1) 

// Modification of morris

// only checking when root->left exists
// if it exists
// going tio righmost node of that left subtree
// connecting its right to cutt->right
// making curr->right = curr->left
// also set curr->left = NULL !!!

// eveytime move curr = curr->right
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
		while (cur)
		{
			if(cur->left)
			{
				TreeNode* pre = cur->left;
				while(pre->right)
				{
					pre = pre->right;
				}
				pre->right = cur->right;
				cur->right = cur->left;
				cur->left = NULL;
			}
			cur = cur->right;
		}
    }
};