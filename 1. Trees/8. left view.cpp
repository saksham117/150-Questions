#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
#include<stack>


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

//Function to return a list containing elements of left view of the binary tree.



void leftViewUtil(vector<int>& output, Node* root, int level, int& max_level)
{
    // base case
    if (root == NULL)
        return;
 
    // If this is the first node of its level
    if (max_level < level) {
        output.push_back(root->data);
        max_level = level;
    }
 
    // Recur for left and right subtrees
    leftViewUtil(output, root->left, level + 1, max_level);
    leftViewUtil(output, root->right, level + 1, max_level);
}
vector<int> leftView(Node *root)
{
   // Your code here
    int max_level = 0; // initialise max_level with 0 here
    vector<int> output;
    // calling util function
    leftViewUtil(output, root, 1, max_level);
    return output;
}

