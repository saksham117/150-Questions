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

// EXACTLY SAME CONCEPT AS PREVIOUS QUESTION
// INSTEAD WE DO NOT STOP WHEN DISTANCE = K
// WE STOP WHEN WE VISTED ALL NODES ONCE
// AND QUEUE BECOMES EMPTY
// WE RETURN DISTANCE -1, AS DISTANCE GETS INCREMENRTED ONE EXTRA TIME



// INTERVIEWBIT
//   Definition for binary tree
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
  
  typedef struct TreeNode TreeNode;
  
  TreeNode* TreeNode_new(int val) {
      TreeNode* node = (TreeNode *) malloc(sizeof(TreeNode));
      node->val = val;
      node->left = NULL;
      node->right = NULL;
      return node;
 }


int solve(TreeNode* root, int B) {

        unordered_map<TreeNode*,TreeNode*> hashMap;
        // also let us create a queue to traverse in BFS fashion
        queue<TreeNode*> q;

        // intially push the root to queue and also mark its parent
        q.push(root);
        hashMap[root] = NULL;

        // go to all nodes and mark their parents in BFS fashion
        // also locate the node
        TreeNode* target = NULL;

        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();

            if(front->val == B){
                target = front;
            }

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

        return distance-1;
    
}


// // gfg
// int solve(Node* root, int B) {

//         unordered_map<Node*,Node*> hashMap;
//         // also let us create a queue to traverse in BFS fashion
//         queue<Node*> q;

//         // intially push the root to queue and also mark its parent
//         q.push(root);
//         hashMap[root] = NULL;

//         // go to all nodes and mark their parents in BFS fashion
//         // also locate the node
//         Node* target = NULL;

//         while(!q.empty())
//         {
//             Node* front = q.front();
//             q.pop();

//             if(front->data == B){
//                 target = front;
//             }

//             if(front->left){
//                 q.push(front->left);
//                 hashMap[front->left] = front;
//             }

//             if(front->right){
//                 q.push(front->right);
//                 hashMap[front->right] = front;
//             }
//         }

//         // now let us first define the distance variable
//         int distance = 0;

//         // we will do a bfs traversal and push all the nodes having unit distance from cureent node
//         // the nodes that will be pushed are left right and parent
//         // after every iteration, we shall increase the distance from the targetNode by 1

//         // also we need to maintain a visited set
//         // so that we do not keep on visiting the same nodes again and again
//         unordered_set<Node*> visited;

//         q.push(target);
//         visited.insert(target);

//         while(!q.empty()){
            
//             // also adding the base case
            

//             //  a vector which stores all the nodes present in the q
//             // they basically rpresent all th nodes at a distance i from the target node
//             vector<Node*> contents;

//             while(!q.empty()){
//                 contents.push_back(q.front());
//                 q.pop();
//             }

//             // doing it for every node
//             for(int i = 0; i < contents.size(); i++){

//                 Node* currNode = contents[i];
                
//                 // inserting the left child
//                 if(currNode->left && (visited.find(currNode->left) == visited.end())){
//                     q.push(currNode->left);
//                     visited.insert(currNode->left);

//                 }

//                 // inserting the right child
//                 if(currNode->right && (visited.find(currNode->right) == visited.end())){
//                     q.push(currNode->right);
//                     visited.insert(currNode->right);
//                 }

//                 // inserting the parent
//                 if(hashMap[currNode] != NULL && (visited.find(hashMap[currNode]) == visited.end()) ){
//                     q.push(hashMap[currNode]);
//                     visited.insert(hashMap[currNode]);
//                 }
//             }

//             distance += 1; // increment the distance when I reach the end of hile construct
//         }

//         // the contents of the q will be the answer

//         return distance;
    
// }







