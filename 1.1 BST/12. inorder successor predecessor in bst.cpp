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
// BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// brute approach 
// store inorder and find succssor and predecessor

// optimal
// use concept of ceil and floor

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root == NULL){
        return;
    }

    findPreSuc(root->left, pre, suc, key);

    // setting predecesor
    if(root->key < key){
        pre = root;
    } 
    // since we are travelling in ascending order, its last update will be when we are at a value just smaller than key

    if(root->key > key && !suc){
        suc = root; 
        return;
    }
    // selecting the value just greater than given value
    // we are checking the second condtion also, coz if we do not while backtracking inorder would set much greater values than just the next 
    // greatest value. so we are doing this to avoid that.

    findPreSuc(root->right, pre, suc, key);
}

// or another approach: apply binary search on the bst
// time complexity is O(h) where h is height of bst 

// approaching it via binary search algorithm
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = NULL;
        
        while (root != NULL) {
            
            if (p->val >= root->val) {
                root = root->right;
            } else {
                successor = root;
                root = root->left;
            }
        }
        
        return successor;
    }
};