// In simple terms, a graph that can be colored using exactly 2 colors, such that no two adjacent nodes have
// the same color

// Or in complex terms
// Bipartite graph, also known as Bigraph is a special graph such that you can divide the vertex set into 2 disjoint sets such that : 

//  1) Each vertex belongs to exactly one of the 2 sets
//  2) Each edge connects vertices of 2 different sets 

// Number of elements need not be the same in both the sets 

// Obaservations
// Any graph having a cycle of odd size, cannot be a bipartite graph
// Rest all can be 

// We take a colour array, which tell what colour has the node been colored with
// but we are not gonna do this
// we are gonna keep things simple

// So what we will do is that we will start with a vertex and mark it wth color 1
// Now if we go to next vertex and its unvisted, we will visit that and mark it with color 2
// however if its visted we check its color
// if its color is same as our current node, we return false,else we continue

// if all nodes satisfy this behaviour, we return true and hence the graph becomes bipartite


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

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int V = graph.size();

        int *visited = new int[V];
        for(int i = 0; i < V; i++){
            visited[i] = -1;
        }

        for(int i = 0; i < V; i++){

            if(visited[i] == -1){

                visited[i] = 0;
                queue<int> q;
                q.push(i);

                while(!q.empty()){
                    
                    int node = q.front();
                    q.pop();

                    for(int i = 0; i < graph[node].size(); i++){
                        int newNode = graph[node][i];

                        // node has not been visited
                        // set it color opposite to our node
                        if(visited[newNode] == -1){
                            
                            visited[newNode] = !visited[node];
                            q.push(newNode);
                        }
                        else
                        // if newNode has been viisted
                        // if its color is same as the node whose neighbors we are checking, then bipartite graph not possible
                        {
                            if(visited[newNode] == visited[node]){
                                return false;
                            }
                        }
                    }
                }
            }
        } 

        return true;
        
    }
};

class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, int* visited){
        
        for(int i = 0; i < graph[node].size(); i++){

            int newNode = graph[node][i];

            // node has not been visited
            // set it color opposite to our node
            if(visited[newNode] == -1){
                
                visited[newNode] = !visited[node];
                bool ans = dfs(graph,newNode,visited);
                if(ans == false){
                    return false;
                }
            }
            else
            // if newNode has been viisted
            // if its color is same as the node whose neighbors we are checking, then bipartite graph not possible
            {
                if(visited[newNode] == visited[node]){
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        int V = graph.size();

        int *visited = new int[V];
        for(int i = 0; i < V; i++){
            visited[i] = -1;
        }

        for(int i = 0; i < V; i++){

            if(visited[i] == -1){

                visited[i] = 0;
                bool ans = dfs(graph,i,visited);
                if(ans == false){
                    return false;
                }
            }
        }

        return true;
    } 
};