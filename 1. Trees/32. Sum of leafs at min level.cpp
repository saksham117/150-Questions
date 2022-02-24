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

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    int minLeafSum(Node *root)
    {
        //code here
        int sum = 0;

        if(root == NULL){
            return 0;
        }

        bool isMinLevel = false;

        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        // return when size of queue is one and top of q is NULL
        while(q.size() > 1 || q.front() != NULL){

            Node* front = q.front();
            q.pop();

            if(front == NULL && isMinLevel){
                break;
            }

            if(front == NULL){
                q.push(NULL);
                continue;
            }

            // if the node is actually a leaf node, add its value to the sum
            // and if isMinLevel is not set, then set it
            if(front->left == NULL && front->right == NULL){
                sum += front->data;
                if(!isMinLevel){
                    isMinLevel = true;
                }
            }

            // if my left child exists
            if(front->left){
                q.push(front->left);
            }

            // if my right child exists
            if(front->right){
                q.push(front->right);
            }
        }

        return sum;

        
        
    }
};

//         1
//       2   3 
//     4  5   8
//       6  7

// q:        N 6 7