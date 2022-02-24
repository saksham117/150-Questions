#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<unordered_set>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {

        unordered_map<Node*, Node*> mapping;
        unordered_set<Node*> visited;
        queue<Node*> q;

        q.push(node);
        visited.insert(node);


        while(!q.empty()){
            
            Node* curr = q.front();
            q.pop();

            Node* newNode = new Node(curr->val);
            mapping[curr] = newNode;

            for(int i = 0; i < curr->neighbors.size(); i++){
                
                Node* temp = curr->neighbors[i];
                if(visited.find(temp) == visited.end()){
                    q.push(temp);
                    visited.insert(temp);
                }
            }
        }

        for(auto it: mapping){

            Node* original = it.first;
            Node* curr = it.second;

            for(int i = 0; i < original->neighbors.size(); i++){
                curr->neighbors.push_back( mapping[original->neighbors[i]] );
            }
        }

        return mapping[node];
        
    }
};