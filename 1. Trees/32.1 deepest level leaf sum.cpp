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


class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {

        int sum = 0;

        if(root == NULL){
            return 0;
        }


        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        q.push({NULL,0});

        int maxLevel = 0;

        while(q.size() > 1 || q.front().first != NULL){
            
            auto p = q.front();
            TreeNode* front = p.first;
            int level = p.second;
            q.pop();

            if(front == NULL){
                q.push({NULL, 0});
                continue;
            }

            // if the node is actually a leaf node, add its value to the sum
            // and if isMinLevel is not set, then set it
            if(front->left == NULL && front->right == NULL)
            {
                if(level > maxLevel)
                {
                    maxLevel = level;
                    sum = 0;
                }

                if(level == maxLevel){
                    sum += front->val;
                }
                
            }

            // if my left child exists
            if(front->left){
                q.push({front->left, level +1});
            }

            // if my right child exists
            if(front->right){
                q.push({front->right,  level +1});
            }
        }

        return sum;
        
    }
};


