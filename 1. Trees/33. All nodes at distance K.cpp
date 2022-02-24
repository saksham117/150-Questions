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

// Looks tough but is fairly simple once you know how to do it and remember the rough steps


// Given the root of a binary tree, the value of a target node target, and an integer k, 
// return an array of the values of all nodes that have a distance k from the target node.

// You can return the answer in any order.

// So this problem requires to travel in the upwards direction
// But in binary tree, it aint possible simply with the given binary tree

// We need to make some parent pointers
// Appraoch
// 1) Start a BFS travel
// 2) We will traverse in the normal fashion and use a map to store the parent pointers of a node 
//    So once we have done the level order traversal once, we will have the parent pointer of every node 
// 3) Next search and store the result of the target node(need to do if address of target s not given and only value is provided)


// 4) Next we need to do bfs again to mark all nodes at distance = k
//    Also use a visted set(hashmap) to track what all nodes have been visited
//  For every node at front of q, push top left and right nodes into q and also send them to visited

// 5) ****Now in next itertaion, pop ALL NODES all at once AND STORE IN VECTOR. THIS STEP IS EXTREMELTY IMPORTAMT****
// and try to push their left, right and top into queue. But push only those nodes which have not been visited






class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        // first let us create a map which will store all the node and thei pointer
        unordered_map<TreeNode*,TreeNode*> hashMap;
        // also let us create a queue to traverse in BFS fashion
        queue<TreeNode*> q;

        // intially push the root to queue and also mark its parent
        q.push(root);
        hashMap[root] = NULL;

        // go to all nodes and mark their parents in BFS fashion
        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();

            if(front->left){
                q.push(front->left);
                hashMap[front->left] = front;
            }

            if(front->right){
                q.push(front->right);
                hashMap[front->right] = front;
            }
        }

        // now let us first define the distance variable
        int distance = 0;

        // we will do a bfs traversal and push all the nodes having unit distance from cureent node
        // the nodes that will be pushed are left right and parent
        // after every iteration, we shall increase the distance from the targetNode by 1

        // also we need to maintain a visited set
        // so that we do not keep on visiting the same nodes again and again
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        while(!q.empty()){
            
            // also adding the base case
            if(distance == k){
                break;
            }

            //  a vector which stores all the nodes present in the q
            // they basically rpresent all th nodes at a distance i from the target node
            vector<TreeNode*> contents;

            while(!q.empty()){
                contents.push_back(q.front());
                q.pop();
            }

            // doing it for every node
            for(int i = 0; i < contents.size(); i++){

                TreeNode* currNode = contents[i];
                
                // inserting the left child
                if(currNode->left && (visited.find(currNode->left) == visited.end())){
                    q.push(currNode->left);
                    visited.insert(currNode->left);

                }

                // inserting the right child
                if(currNode->right && (visited.find(currNode->right) == visited.end())){
                    q.push(currNode->right);
                    visited.insert(currNode->right);
                }

                // inserting the parent
                if(hashMap[currNode] != NULL && (visited.find(hashMap[currNode]) == visited.end()) ){
                    q.push(hashMap[currNode]);
                    visited.insert(hashMap[currNode]);
                }
            }

            distance += 1; // increment the distance when I reach the end of hile construct
        }

        // the contents of the q will be the answer
        vector<int> ans;

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};


