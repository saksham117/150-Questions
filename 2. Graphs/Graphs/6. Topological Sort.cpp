// Topological sortings's practical application is in OS, where it is used for resolving deadlocks.

// WHAT IS TOPOLOGICAL SORT??

// Suppose we have a dependency graph (lets say, a graph containing steps for a particular task which need to be 
// followed in a particular  order). 
// Toplogical sort gives us a valid sequence in which these steps are to be performed so that no problems arise.
//  so for a task, all of its dependecies must be done before it in order for it to be considered a valid topo sort.
// or in technical terms
// if there is an edge from u to v
// then in topo sort order, u will always appear v, and this iwll be true for all the vertices


// So after topolgical sorting, if we arrange the vertices in one valid topo sort, then all edges go from left to right
// only possible for directed acyclic graph

// ###################KAHNS ALGORITHM FOR TOPOLOGICAL SORTING##############################

// The runnig time for the same is O(V+E) which is same as bfs and dfs

// The basic algorithm is that at each iteration, we select the node with zero indegree, meaning that node has no incoming edges
// or all of its dependencied have already been met
// indegree is the number of incoming edges for a node


// If there exists a cycle in a directed graph, then topological sorting is not possible
// this will be automatically managed as we wont get a vertez having zero indegree
// TOPO SORTING IS NOT UNIQUE. We can have more than one toposort for the same graph
// if we want to print the lexicographically smallest order, then we can use a minimum priority queue

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

void kahn(unordered_map<int, vector<int> *> Graph ,int n, int* in, vector<int>& result){

    queue<int> q;
    // pushing all the nodes into the queue which have zero indegree
    for(int i = 1; i <=n; i++){
        if(in[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int curr = q.front();
        result.push_back(curr);
        q.pop();

        // for every node having zero indegree, check for its descendants
        // first reduce their indegree and then if there indegree also becomes zero, add it to the queue
        for(int i = 0; i < Graph[curr]->size(); i++){

            int node = Graph[curr]->at(i);
            in[node]--;

            if(in[node] == 0){
                q.push(node);
            }
        }
    }
}

int main()
{
    int n, m; // edges and vertices
    // fill the graph over here
    cout<<"Enter the number of vertices: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>m;

    unordered_map<int, vector<int> *> Graph;
    int* in = new int[n+1]; // array to store the indegree
    // creating the template for adjancey list
    for(int i = 1; i <=n ; i++)
    {   
        // I miss this line often, after the eqal to one
        vector<int> * vec = new vector<int>();
        Graph[i] = vec;
    }

    for(int i = 1; i <= m; i++)
    {   
        int x,y;
        cout<<"Enter the first vertex: ";
        cin>>x;
        cout<<"Enter the second vertex: ";
        cin>>y;

        Graph[x]->push_back(y);
        in[y] += 1;
    }


    vector<int> result; // stores the topo sort for the vertices
    kahn(Graph,n,in,result);
    if(result.size()== n+1){
        cout<<"Toposort exists";
    }
    else{
        cout<<"Toposort does not exists";
    }
    return 0;
}



// GFG link

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here

        // first of all creating and filling the inDegree array
        vector<int> inDegree(V);
        for(int i = 0; i < V; i++){
            inDegree[i] = 0;
        }

        // now I will iterate over the graph to set the inDegree of all the vertices;
        for(int i = 0; i < V; i++){
            // iterating over the neighbours of each of the node in the graph
            for(int j = 0; j < adj[i].size(); j++){
                int currentNode = adj[i][j];
                inDegree[currentNode] += 1; // as this is an edge from node i -> currentNode, incrementing inEdge of curretnNode by 1
            }
            
        }

        queue<int> q;
        // pushing all the vertices having 0 indegree into the queue

        for(int i = 0; i < V; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans; // to store the topo sort
        // if no vertex has 0 indegree, return the empty ans vector
        if(q.size() == 0){
            return ans;
        }

        while(!q.empty()){
            
            int currentNode = q.front();
            q.pop();
            ans.push_back(currentNode);

            // reducing the indegree of the neighbours of the current node
            for(int i = 0; i < adj[currentNode].size(); i++){
                int newNode = adj[currentNode][i];

                inDegree[newNode] -= 1;

                // if by doing so, indegree of one node becomes 0, push that into queue as well
                if(inDegree[newNode] == 0){
                    q.push(newNode);
                }
            }

        }

        return ans;
    }
};