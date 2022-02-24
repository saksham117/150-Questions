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

// is simply top view
// only differnce is that now we just need to store last element across each vertical
// and for that we keep on updating the value in the map
// and at the end the map will always be updated with ther last value along the vertcal
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
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

            
            nodes[x] = node->data;
           

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