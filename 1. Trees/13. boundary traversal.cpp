// Boundary traversal is basically composed of the follwoing three
// 1) Left boundary excluding the leaf node
// 2) Leaf nodes
// 3) Right boundary in reverse direction excluding the leaf node 

// left boundary can be achieved by going to root->left and continuing till we enconter a leaf node 

// for leaf nodes we have to do inorder traversal
// Basically traverse the whole tree and just put the leaf nodes in the data structure we are using 

// similar;ry for right just start traversal from root's right and continue till we encounter a leaf node
// store this traversal in a stack as we need it to be in reverse order 
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


class Solution {
public:
    // pnly differnce between this and leftView is the if else. In leftvoew we used to go right everytime and used to filter out nodes by using depth
    // here if left exists, no need to go right
    void leftBoundary(Node *root, vector<int>& ans){

         // if leaf node
        if(!root->left && !root->right){
            return;
        }

        ans.push_back(root->data);

        // if left exists and if not then only go to right
        if(root->left){
            leftBoundary(root->left, ans);
        }
        else{
            leftBoundary(root->right, ans);
        }
    }

    void rightBoundary(Node *root, stack<int>& s){
        
       // if leaf node
        if(!root->left && !root->right){
            return;
        }

        s.push(root->data);

        // if right exists and if not then only go to left
        if(root->right){
            rightBoundary(root->right, s);
        }
        else{
            rightBoundary(root->left, s);
        }
    }

    void leafNodes(Node* root, vector<int>& ans){

        if(root == NULL){
            return;
        }
        // leaf node
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }

        leafNodes(root->left, ans);
        leafNodes(root->right, ans);


    }

    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans; 

        if(root == NULL){
            return ans;
        }

        ans.push_back(root->data);

        // if there is a single node
        if(root->left == NULL && root->right == NULL){
            return ans;
        }

        if(root->left){
            leftBoundary(root->left, ans);
        }

        leafNodes(root, ans);

        stack<int> s;

        if(root->right){
            rightBoundary(root->right, s);
        }

        while(!s.empty()){
            int top = s.top();
            s.pop();
            ans.push_back(top);
        }

        return ans;
    }
};