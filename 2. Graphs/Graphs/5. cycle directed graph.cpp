#include<iostream>
#include<vector>
using namespace std;

// Interesting observation
// Since TOPO sort only works on directed Acyclic Graphs, therefore if we try to find topo sort of this graph
// then if it returns a valid topo sort, then return no loops
// else cycle exists

// similar to cycle in undirected graph
// only new thing is that we maintain a recursion stack and some if else connditions change

// earliest code
class Solution {
public:
     bool dfs(vector<int>adj[], bool *visited, bool *rec, int vertex, int parent)
    {
        visited[vertex] = true;
        rec[vertex] = true;
        for(int i =0; i < adj[vertex].size(); i++)
        {
            int node = adj[vertex][i];
            if(visited[node])
            {
    
                if(rec[node] == true || node == parent)
                {
                    return true;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                
                bool ans = dfs(adj, visited, rec, node, vertex);
                if(ans == true)
                {
                    return true;
                }
            }
        }
        
        rec[vertex] = false;
        return false;
    }
    
	bool isCyclic(int V, vector<int> adj[]) {
	   	// code here
	   	bool *visited = new bool[V];
        bool* rec = new bool[V];

        for(int i = 0; i < V; i++)
        {
            visited[i] = false;
            rec[i] = false;
        }

        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {   
                visited[i] = true;
                rec[i] = true;
                bool ans = dfs(adj, visited,rec, i, -1);
                if(ans)
                {
                    return ans;
                }
                else{
                    continue;
                }
            }
        }
        
        return false;

	}
};


class Solution {
  public:
    bool dfs(vector<int> adj[], int node, bool* visited, int* rec){

        for(int i = 0; i < adj[node].size(); i++){
            
            int newNode = adj[node][i];
            // if node has been visited and is a part of the recusrive stack, then there indeed is a loop
            if(visited[newNode] == true && rec[newNode] == 1){
                return true;
            }

            // else the standar opearion, visot next node in depth if not visited
            if(!visited[newNode]){
                visited[newNode] = true;
                rec[newNode] = true;
                bool ans = dfs(adj,newNode,visited,rec);
                if(ans){
                    return ans;
                }
            }
        }

        rec[node] = false; // mark it out of rec stack once all of its neighbours are visited
        return false;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        bool* visited = new bool[V];
        int* rec = new int[V];

        for(int i = 0; i < V; i++){
            visited[i] = false;
            rec[i] = 0;
        }

        // this ensures it works for unconnected components as well
        for(int i = 0; i < V; i++){
            if(visited[i] == false){
                visited[i]  = true;
                rec[i] = 1;
                bool ans = dfs(adj,i,visited,rec);
                if(ans){
                    return ans;
                }
            }
        }

        return false;
    }
};

