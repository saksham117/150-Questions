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
// https://practice.geeksforgeeks.org/problems/children-sum-parent/1/

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

// pretty basic
// normal recursive traversal of tree

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
    //  base case
        if(root == NULL || root->left == NULL && root->right == NULL){
            return 1;
        }
        
        int left = isSumProperty(root->left);
        int right = isSumProperty(root->right);
        
        int sum = 0;
        if(root->left){
            sum += root->left->data;
        }
        
        if(root->right){
            sum += root->right->data;
        }
        
        if(left && right && sum == root->data){
            return 1;
        }
        
        return 0;
        
        
    }
};

// did this while revising
class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
     if(root == NULL || (root->left == NULL && root->right == NULL)){
         return true;
     }
     
     int sum = 0;
     
     if(root->left){
         sum += root->left->data;
     }
     
     if(root->right){
         sum += root->right->data;
     }
     
     if(sum != root->data){
         return false;
     }
     
     return isSumProperty(root->left) && isSumProperty(root->right);
     
    }
};