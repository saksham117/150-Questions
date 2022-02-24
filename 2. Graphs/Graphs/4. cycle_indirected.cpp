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

// if node is visited and is not parent, then there is a loop

// BFS
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here

        // intializing the array
        bool* visited = new bool[V];
        for(int i = 0; i < V; i++){
            visited[i] = false;
        }

        for(int j = 0; j < V; j++){ // ensure we check all connected components
            if(visited[j] == false){

                visited[j] = true;
                queue<pair<int,int>> q;
                q.push({j,-1}); // this is the starting node, as no parent

                while(!q.empty()){

                    int front = q.front().first; // we need to see this nodes edges
                    int parent = q.front().second;  // this is the parent for the next set of nodes we will be seeing
                    q.pop(); 

                    for(int i = 0; i < adj[front].size(); i++){
                        
                        int node = adj[front][i];
                        if(node != parent && visited[node] == true){ // if this is the condition, then it is a loop
                            return true;
                        }
                        else if(!visited[node]){ // parent for this node will be front
                            visited[node] = true;
                            q.push({node,front});
                        }
                    }
                }
            }
        }
        
        return false;
    }
};


// DFS
class Solution {
  public:
    bool dfs(vector<int> adj[], int node, int parent, bool*visited){
        for(int i = 0; i < adj[node].size(); i++){
                        
            int newNode = adj[node][i];
            if(newNode != parent && visited[newNode] == true){ // if this is the condition, then it is a loop
                return true;
            }
            else if(!visited[newNode]){ // parent for this node will be front
                visited[newNode] = true;
                bool ans = dfs(adj,newNode,node,visited);
                if(ans){
                    return ans;
                }
            }
        }

        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here

        // intializing the array
        bool* visited = new bool[V];
        for(int i = 0; i < V; i++){
            visited[i] = false;
        }

        for(int j = 0; j < V; j++){ // ensure we check all connected components
            if(visited[j] == false){

                visited[j] = true;
                bool ans = dfs(adj,j,-1,visited);
                if(ans){
                    return ans;
                }
            }
        }
        return false;
    }
};