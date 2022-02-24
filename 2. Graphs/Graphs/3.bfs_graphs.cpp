#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>

using namespace std;

// Also if we have some disconnected components then we need to run that dfs for all those components
// like basically start a for loop and go to the first unvisited vertex, and continue

// Note: 
// Passing graph as this will also work: unordered_map<int, vector<int>>
// Just note that you pass by reference
// I prefer passing as a pointer. But other way will also work
// checked using leetcode course schedule code


void bfs(unordered_map<int, vector<int> *> graph, bool *visited, int vertex)
{
    queue<int> q;

    q.push(vertex);
    visited[vertex] = true;

    while(q.empty() == false)
    {
        int top = q.front();
        q.pop();

        cout<<top<<endl;

        for(int i = 0; i < graph[top]->size(); i++)
        {
            int vertex2 = graph[top]->at(i);
            if(!visited[vertex2])
            {   
                visited[vertex2] = true;
                q.push(vertex2);
            }
            else
            {
                continue;
            }
        }
    }
}

int main(){

    int V;
    int E;

    cout<<"Enter the number of vertices: ";
    cin>>V;
    
    cout<<"Enter the number of edges: ";
    cin>>E;

    unordered_map<int, vector<int> *> adjList;

    // creating the template for adjancey list
    for(int i = 0; i < V; i++)
    {   
        // I miss this line often, after the eqal to one
        vector<int> * v = new vector<int>();
        adjList[i] = v;
    }

    for(int i = 0; i < E; i++)
    {   
        int v1,v2;

        cout<<"Enter the first vertex: ";
        cin>>v1;
    
        cout<<"Enter the second vertex: ";
        cin>>v2;

        adjList[v1]->push_back(v2);
        adjList[v2]->push_back(v1);
    }

    bool* visited = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    bfs(adjList,visited,0);

    return 0;
}
