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

 int findCeil(TreeNode *root, int key){

	int ceil = -1; 
    while (root) {

        if (root->val == key) {
            ceil = root->val;
            return ceil;
        }
 
        if (key > root->val) {
            root = root->right;
        }
        else {
            ceil = root->val; 
            root = root->left;
        }
    }
    return ceil; 
}