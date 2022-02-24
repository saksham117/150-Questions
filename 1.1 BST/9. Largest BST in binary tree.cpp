// / Tree node structure  used in the program
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


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
// Note: Here Size is equal to the number of nodes in the subtree

// Brute force approach
// Go to every node
// see if its a bst or not
// then recur to left and right child and see if they are bst or not
// basically using the INT_MAX and INT_MIN technique

// Optimized
// Just like we checked in validate BST
// for this we will check for the root, if its greater than the largest value in the left subtree
// and smaller than the smallest value in the right subtree
// so the tree centered at that root, will be a BST

// also size will be 1 + leftSubtree Size + rightSubtree size
// we will define a class haing largest,smallest and size

// if its a leaf node we will return leaf->val, leaf-val,1 (max,min,size)
// if there is a null node return (INT_MIN, INT_MAX, 0)

// if a node does not satisfy the property
// pass the count as such, but pass INT_MAX as the MAX and INT_MIN as the min


class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    class Info{
        public:
        int count;
        int maximum;
        int minimum;

        Info(int count, int maximum, int minimum){
            this->count = count;
            this->maximum = maximum;
            this->minimum = minimum;
        }
    };

    Info helper(Node* root){

        // if we are a NULL node
        if(root == NULL){
            return Info(0,INT_MIN,INT_MAX);
        }

        // if we are the leaf node
        if(root->left == NULL && root->right == NULL){
            return Info(1, root->data, root->data);
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        if(root->data > left.maximum && root->data < right.minimum){
            int size = left.count + right.count + 1;
            int maximum = max(root->data, right.maximum);
            int minimum = min(root->data, left.minimum);

            return Info(size,maximum,minimum);
        }
        else{
            return Info(max(left.count, right.count), INT_MAX, INT_MIN);
        }
    }

    int largestBst(Node *root)
    {
    	//Your code here
        auto ans = helper(root);
        return ans.count;
    }
};



