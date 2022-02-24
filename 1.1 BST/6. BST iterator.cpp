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

// Given as BST like 

//     7
//   3  15
//     9  20

// Its inorder will be 3 7 9 15 20

// There will be two functions
// next and hasnext

// next returns the next smallest value in the bst
// so initially next will point to NULL
// on calling next once, we will get 3
// then on next call 7, then 9 and so on

// hasNext basically tells that if I am on this particlur node
// does it have a next node or not


// Approach 1
// Maintain a vector and store the inorder inside of it. In that case the 3 functions become trivial
// So we take time time O(N) and space O(N) for traversing once and storing the inorder in a vector


// Approach 2. We need to solve this in O(h) space 

// So take a stack
// In the constructor, root is given
// so from the root, go to extreme left and store all elements inside the stack
// if we get next, pop the top element from stack and return it 
// if the popped element does not have a right. simply pop it and do nothng
// if it does have, first push the right node
// and then from that node, go till the extreme left
// just rinse and repeat

// Now if someone calls hasNext functions
// then if stack size > 0, return yes
// we do have a next

// So its simply iterative inorder
// but only till heigh h and not complete inorder till all elements

class BSTIterator {
public:
    stack<TreeNode*> s;

    // so from the root, go to extreme left and store all elements inside the stack
    BSTIterator(TreeNode* root) {
        while(root){
            s.push(root);
            root = root->left;
        }
    }
    
    int next() {

        TreeNode* top = s.top();
        s.pop();
        if(top->right){
            TreeNode* temp = top->right;
            while(temp){
                s.push(temp);
                temp = temp->left;
            }
        }

        return top->val;
        
    }
    
    bool hasNext() {
        if(s.size() > 0){
            return true;
        }
        return false;   
    }
};

// Space complexity is O(H)
// Time is averaged out O(1)
// as for some calls we just return
// for othere we push
// so at max for N nodes, in all we would have to push N times
// so approac its O(N/N) = 1