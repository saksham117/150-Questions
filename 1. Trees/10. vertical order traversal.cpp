// Condition
// If nodes overlap, either we can show the left one first, then right one
// or in this case (ie this solution), if two nodes are at the same row and column, we are printing the 
// one which is smaller in value

// we are going to make use of the x-y coordinates to solve it
// like we will have cols as -2, -1, 0 , 1, 2
// we can aslo define columns as we traverse level by level
// like level o, level 1 and so on
// so we have established a sort of x-y co ordinate system

//  so we will be using a queue. where in each element of queueu will be (Node, x -cord, y-cord) or (Node, vertical, level)
// we will be storing results veertical vise and level wise as follows
// map<int, map<int, multiset<int>>> 
// where first int represents vertical
// secon d int represents level
// a multiset allows us to store dupilcate items and that to in a sorted order
// we could also have used a minHeap (PQ) in case of multiset


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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, map<int,multiset<int>>> nodes; // to store nodes vertical wise and level wise
        queue<pair<TreeNode* , pair<int, int>>> todo; // queue that we are gonna use for level order traversal

        todo.push({root, {0,0}});

        while(!todo.empty()){

            auto p = todo.front();
            todo.pop();

            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;

            nodes[x][y].insert(node->val);

            if(node->left){
                todo.push({node->left, {x - 1, y + 1}}); // updating the co ordinates
            }

            if(node->right){
                todo.push({node->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> ans;

        // here first and second are for when we use iterator and then we need to iterate over stuff
        for(auto p : nodes){
            vector<int> col;

            for(auto q: p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }

            ans.push_back(col);
        }

        return ans;


    }
};

