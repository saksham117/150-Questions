
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
#include<stack>


using namespace std;

// https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723
    // Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    	
    if(root == NULL || root->left == NULL && root->right == NULL){
        return;
    }
   
    int beforeUpdation = 0;
    
    if(root->left){
        beforeUpdation += root->left->data;
    }
    
     if(root->right){
        beforeUpdation += root->right->data;
    }
    
    if(beforeUpdation <= root->data){
        if(root->left){
            root->left->data = root->data;
		}
		if(root->right){
            root->right->data = root->data;
        }
    }
    
    changeTree(root->left);
    changeTree(root->right);
    
    int afterUpdation = 0;
    if(root->left)
    {
        afterUpdation += root->left->data;
    }

	if(root->right){
        afterUpdation += root->right->data;
    }

	root->data = afterUpdation;
    
    return;
    

    
}  


// This approach work because there is no limit ki we want the smallest possible such tree or minimal increase or something
// before going to left and right
// we are seeing if left + right <= root
// if yes then we are updating left and right to roots value
// then we make recursive calls

// when we are returning, it might be the case tha left and right got further incremenetd
// so what we will do is set root = left + right

// So a very elegant solution