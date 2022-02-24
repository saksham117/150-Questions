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
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
         if(root == NULL){
            return root;
        }

        queue<Node *> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){

            Node* top = q.front();
            q.pop();

            if(top != NULL)
            {
                top->next = q.front();
                q.push(top->left);
                q.push(top->right);
            }
            else{
                if(q.front() == NULL){
                    break;
                }
                else{
                    q.push(NULL);
                }
            }
        }

        return root;
    }
};

// this is the sort of refined code, I wrote while attempting it the second time
// got inspired from max width of binary tree
class Solution {
public:
    Node* connect(Node* root) {
        
        if(root == NULL){
            return root;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                Node* curr = q.front();
                q.pop();
                

                if(q.size() != 0 && i != size -1){
                    curr->next = q.front();
                }
                
                if(curr->left){
                    q.push(curr->left);
                }
                
                if(curr->right){
                    q.push(curr->right);
                }
            }
        }
        
        return root;
    }
};




// O(1) space solution
void connect(Node *root) {
    if(root == NULL)
        return;
        
    if(root->left != NULL) root->left->next = root->right;
    if(root->right != NULL && root->next != NULL) root->right->next = root->next->left;

    
    connect(root->left);
    connect(root->right);
    }


// solved this while revising (24/2/2022)


class Solution {
public:
    void helper(Node* root) {
        if(root == NULL){
            return;
        }
        
        if(root->left){
            root->left->next = root->right;
        }
        
        if(root->right && root->next) {
            root->right->next = root->next->left;
        }
        
        helper(root->left);
        helper(root->right);
        
    }
    Node* connect(Node* root) {
        
        
        helper(root);
        return root;
        
    }
};