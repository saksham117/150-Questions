// Definition for a Node.
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

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    int maxDepth(Node* root) {
        
        if(root == NULL){
            return 0;
        }
        
        int depth = 0;
        
        for(int i = 0; i < root->children.size(); i++){
            depth = max(depth, maxDepth(root->children[i]));
        }
        
        return 1 + depth;
    }
};