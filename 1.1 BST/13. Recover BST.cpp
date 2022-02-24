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


// brute force method
// do an inorder traversal and store it in a vector )it should have ideally given the sorted list, but since nodes are swapped,
// it wont)
// then sort that to get the correct inorder
// traverse the tree again in inorder fashion
// if the nodes and arr[i] match, well and good
// else enter the correct value from the sorted vector
// time will be O(Nlogn) cox we are sorting
// space also O(N)

// better approach

// now once I get the inorder
// there can be 2 case
// either the swapped elements will be adjacent
// or they wont be

// case 1: swapped nodes not adjacent
// case 2: swapped elements are adjacent

// so actually we do not have to maintain the inorder
// handling case 1
// 3 25 7 8 10 15 20 5 
// start a variable prev
// and whenever you are on any node
// check if prev > curr
// if thats the case, I have found one node which is in wrong position
// similarly find the second one

// in case 2
// 3 5 8 7 10 15 20 25
// there will be no second violation
// so what we do is
// whenever we get the first violation
// store both prev and curr
// so first = prev and second = curr

// if I am in case 2, my first and second need to be swapped

// however if I am in case 1, first will be pointing to the first misplaced node
// second will be updated to point to the next misplaced not

// so during first violation, it is important to maintain both prev and curr so that case2 is also handled

// time is o(N)
// space is O(1)



class Solution {
public:
    
    void helper(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& second){
        
        if(root == NULL){
            return;
        }
        
        helper(root->left, prev, first,second);
//         do my businness
        if(prev != NULL && prev->val > root->val){
//             if first violation
                if(first == NULL){
                    first = prev;
                    second = root;
                }
//             if second violation
                else{
                    second = root;
                }
        }
        
        prev = root;
        
        helper(root->right, prev,first,second);
        
        
    }
    
    void recoverTree(TreeNode* root) {
        
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* prev = NULL;
        
        helper(root, prev,first,second);
        
//         swapping
        // int temp = first->val;
        // first->val = second->val;
        // second->val = temp;
        swap(first->val, second->val);
        return;
        
    }
};