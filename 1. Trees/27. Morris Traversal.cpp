// 2 questions: 
// 1) Recover Binary Search Tree
// 2) Flatten BT to LL 

// Using morris traversal space complexity is O(1) and time is almost but slighlty greater than O(N)
// Space complexity is what makes it stand out

// We basically use the concept of threaded binary tree

// inorder is basically left Root right 

// Cases
// 1) If root->left == NULL, then push root to inorder and go right 
// 2) If root->left, go to the righmost node in root->left subtree and call that as prev
// 3) mark prev->right = root; (this root will be pointed by curr pointer) (created the thread)
// 3.1) If the prev->right is already pointing to curr, then that means we have fully explored this subtree
//      Break the thread and go back to curr
// 4) The continue to left only if 3 and not 3.1
// 5) If 3.1 go to right.


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

vector<int> inOrder(TreeNode* root){
    vector<int> inorder;
    TreeNode* curr = root;

    while(curr != NULL){
        // 1st esdge case
        if(curr-> left == NULL){
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        else{
            // if left exists
            TreeNode* prev = curr->left; 

            // traverse to the righmost node in that subtree
            while(prev->right && prev->right != curr){
                prev = prev->right;
            }

            // 2 case
            // if rightmost nodes -> right == NULL
            if(prev->right == NULL){
                prev->right = curr; // created the thread
                curr = curr->left; // continue traversal
            }
            // it will be pointing to curr
            else {
                prev->right = NULL; // we broke the thread
                inorder.push_back(curr->val); // we added it to inorder as complete left is now explored 
                curr = curr->right; // now we go to right
            }
        }
    }

    return inorder;
}


vector<int> preOrder(TreeNode* root){
    vector<int> preorder;
    TreeNode* curr = root;

    while(curr != NULL){
        // 1st esdge case
        if(curr-> left == NULL){
            preorder.push_back(curr->val);
            curr = curr->right;
        }
        else{
            // if left exists
            TreeNode* prev = curr->left; 

            // traverse to the righmost node in that subtree
            while(prev->right && prev->right != curr){
                prev = prev->right;
            }

            // 2 case
            // if rightmost nodes -> right == NULL
            if(prev->right == NULL){
                preorder.push_back(curr->val); // just this line ka diff between inoirder and preorder 
                // (as before exploring left, we insert the root into the traversal)
                prev->right = curr; // created the thread
                curr = curr->left; // continue traversal
            }
            // it will be pointing to curr
            else {
                prev->right = NULL; // we broke the thread
                curr = curr->right; // now we go to right
            }
        }
    }

    return preorder;
}


// I codeed this
// is very logical once you get the hang of this
// no rocket science at all
// is easy
// 2 cases
// root->left does not exists

// root left exists
// if yes, go to righmost node of subtree rooted at root->left
// CASE 1 if its right == NUll
// Cse 2 if its right == curr

// and move curr accordingly
// see their blog post
// draw the example
// draw the threads
// you eill know why we drew these threads and how to use them
// only when I create the thread, then move to left
// else always move rihgt
// just one change between inorsder and preorder
// in inorder, we were pushing curr, during thread deletion
// in preorder we are pushing it during thread creation

vector<int> inOrder(TreeNode* root){

    vector<int> output;
    
    if(root == NULL){
        return output;
    }

    TreeNode* curr = root;

    while(curr != NULL){

        if(curr->left == NULL){
            output.push_back(curr->val);
            curr = curr->right;
        }
        else{
            TreeNode* prev = curr->left;

            while(prev->right != NULL && prev->right != curr){
                prev = prev->right;
            }

            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            }
            else{
                prev->right = NULL;
                output.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
}