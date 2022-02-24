// Problem Link: https://www.interviewbit.com/problems/path-to-given-node/

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


void helper(TreeNode* root, int B, vector<int>& path, int& flag){

    if(root == NULL || flag == 1)    
    {
        return;
    }

    if(root->val == B){
        flag = 1;
        path.push_back(root->val);
        return;
    }

    path.push_back(root->val);
    helper(root->left, B, path, flag);
    helper(root->right, B, path, flag);

    if(flag == 0){
        path.pop_back();
    }

    return;
}


vector<int> solve(TreeNode* A, int B) {

    vector<int> path;

    if(A == NULL){
        return path;
    }

    int flag = 0;

    helper(A,B,path, flag);

    if(flag == 1)
    {
        return path;
    }
    else {
        vector<int> ans; 
        return ans;
    }
}

//2ND APPROACH
// using bfs appraoch
// had to use parent array(map) to trace the path 

vector<int> solve(TreeNode* A, int B) {
    
    vector<int> path;
    queue<TreeNode*> q;
    unordered_map<TreeNode*, TreeNode*> parent;

    q.push(A);
    TreeNode* node;

    while(!q.empty()){

        TreeNode* element = q.front();
        q.pop();
        if(element->val == B){
            node = element;
            break;
        }

        if(element->left){
            parent[element->left] = element;
            q.push(element->left);
        }

        if(element->right){
            parent[element->right] = element;
            q.push(element->right);
        }
    }


    path.insert(path.begin(), B);

    if(A->val == B){
        return path;
    }


    TreeNode* parentNode = parent[node];

    while(parent.find(parentNode) != parent.end()){
        path.insert(path.begin(), parentNode->val);
        parentNode = parent[parentNode];
    }

    path.insert(path.begin(), A->val);
    
    return path;

}
