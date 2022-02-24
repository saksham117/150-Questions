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
    int widthOfBinaryTree(TreeNode* root) {
        
        // base case
        if(root == NULL){
            return 0;
        }

        int ans = 0;
        // quees storing node and its index
        queue<pair<TreeNode*, int>> q;

        // initializing queue and using 1 based indexing
        q.push({root, 1});

        while(!q.empty()){

            int size = q.size(); // returns current queue size
            int mmin = q.front().second; // retreiving the smallest value in that level
            // this helps in starting index of each level from 1 and thus prevents integer overflow
            // while assigning indices to the nodes 

            // we cannont simply subttract by 1 always
            // coz there are gonna be cases when the left half has leaf nodes at a very shallow depth
            // and only right tree has some nodes. In that case the starting index will be a big number and not 1
            // see example photo

            int first, last; // store index of first and last node in that level

            for(int i = 0; i < size; i++){
                int cur_id = q.front().second - mmin; // index of the node at that level
                TreeNode* node = q.front().first; // retreiving the node
                
                q.pop();

                // if we are just starting in queue, then that index is first
                if(i == 0){
                    first = cur_id;
                }
                // if we are at last element of queue then we are at thr last index
                if(i == size -1){
                    last = cur_id;
                }

                if(node->left){
                    q.push({node->left, cur_id*2 + 1});
                }

                if(node->right){
                    q.push({node->right, cur_id*2 + 2});
                }
            }

            ans = max(ans, last - first + 1);
        }

        return ans;

    }
};