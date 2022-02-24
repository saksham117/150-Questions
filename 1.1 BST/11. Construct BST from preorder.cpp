#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Methods
// Brute force
// we are given preorder
// So we know that 1st node is always gonna be the root
// so we set that as root and for all other nodes we check at which position it can get inserted
// Time O(NxN)
// space O(1)

// better
// sort the array and you will get inorder
// now you have both inorder as well preorder
// construct a unique tree using that. This question we had covered in BT series 
// time O(nlogn + n)
// space O(N)

// optimal
// we will be using thr logic of checking if bt is bst or not (inf and -inf) concept

// now set upperbound as INT_MAX
// so take first element as 8(root)

// now all elements to left of it have to be less than 8
// so upper bound for left half is 8

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0;
        return build(A, i, INT_MAX);
    }

    TreeNode* build(vector<int>& A, int& i, int bound) {
        if (i == A.size() || A[i] > bound) return NULL;
        TreeNode* root = new TreeNode(A[i++]);
        root->left = build(A, i, root->val);
        root->right = build(A, i, bound);
        return root;
    }
};