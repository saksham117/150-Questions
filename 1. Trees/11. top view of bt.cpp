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

// A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// just vertical order traversal but with less complexity
// as i just need to extract the first element from each vertical
// and not maintain all the elemenst across the vertical

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        map<int, int> nodes;
        queue<pair<Node*, int>> todo;
        vector<int> ans; 

        if(root == NULL){
            return ans;
        }

        todo.push({root, 0});

        while(!todo.empty()){

            auto p = todo.front();
            todo.pop();

            Node* node = p.first;
            int x = p.second;

            if(nodes.count(x) == 0){
                nodes[x] = node->data;
            }

            if(node->left){
                todo.push({node->left, x - 1});
            }

            if(node->right){
                todo.push({node->right, x + 1});
            }

        }

        

        for(auto it : nodes){
            ans.push_back(it.second);
        }

        return ans;

    }

};
