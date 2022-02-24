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

// We will be given a weighted graph
// Spanning tree is one, that when you convert a graph into a tree, it contains excalty N nodes and N-1 edges
// Every Node should be reachable by every other node 

// It will be a minimum spanning tree, if among all spanning trees, the cost of the edges is the minimum

// We will start with any vertex
// We will find its mininmum edge
// After getting our second vertex
// We will find the minimum edge of all the nodes currently in our MST
// then we select that node
// now we have 3 nodes
// repeat the above process for all the nodes
// we search for the minimum edge amongst all the nodes in our MST

// Approach 
// We would have 3 arrays(key, mst and parent). 

// Significance of all three arrays:
// Key : This array holds the weight/ cost of the MST(intialized to INT_MAX except the index 0 
// which is set with value of zero)
// We use this array to select our next minimum edge which is no part of MST

// MST : This is a boolean array which indicates whether a node is already a part of MST or not
// (initialized to false except the index 0 which is true)

// Parent :  This indicates the parent of a particular node in the MST(initialized to -1)
// this is useful in getting back the nodes and edge of the MST
// if we consider 0 as the source
// then all the indixes from 1 to N-1 will be considered
// where there will be an edge from arr[i] -> i


// Steps:
// Assuming we start with node 0, the index 0 in the key array is initialized to zero(because it is the first node in the MST). 
// We find the index/node in the key array which has the minimum weight. We then find all its adjacent edges and pickup 
// the one with minimum weight. 
// Also at the same time we mark this node as true(indicating that it is now a part of the MST) 
// and also set it’s parent as node ‘0’.

// After this, we would continue to find the one with minimum weight in the key array that is not a part of the MST
// (Notice that this is where we ensure that we pickup the node with minimum weight and we do not choose an edge that 
// might cause a cycle)

// We continue this process until all nodes become a part of the MST

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

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // declaring thr 3 arrays
        int* key = new int[V];  // same as distance array
        bool* mst = new bool[V]; // same as visited
        int* parent = new int[V]; // this parent can also be used in Dijkstras to calculate path from node to source

        // intializing them
        for(int i = 0; i < V; i++){
            key[i] = INT_MAX;
            mst[i] = false;
            parent[i] = -1;
        }

        key[0] = 0;
        // parent[0] = -1;
        // mst[0] = true;

        // repeat this V-1 times
        // because we just want V-1 edges
        for(int i = 0; i < V-1; i++){

            // selecting the node with min weight and also it should not be a part of the mst
            int minNode;
            int minValue = INT_MAX;

            for(int v = 0; v < V; v++)
            {
                if(mst[v] == false &&  key[v] < minValue){
                    minValue = key[v];
                    minNode = v;
                } 
            }

            // since this is the minNode, marking it as true and made a part of MST
            mst[minNode] = true;


            // after that iterating for all the nodes of the of the give minNode
            for(int j = 0; j < adj[minNode].size(); j++)
            {    
                vector<int> newNode = adj[minNode][j];
                int v = newNode[0];
                int weight = newNode[1];

                // if that node is alreafy not part of mst and its weight is less than key
                // weight represents distance from minNode->newNode
                // also set the parent
                if(mst[v] == false && weight < key[v]){
                    parent[v] = minNode;
                    key[v] = weight;
                }
            }


        }

        int sum = 0;
        for(int i = 0; i < V; i++)
        {
            sum += key[i];
        }

        // if we had to print the edges too
        for (int i = 1; i < V; i++) 
            cout << parent[i] << " - " << i <<" \n"; 
	

        return sum;

    }
};  

// Time Complexity: O(N^2). Going through N Node for N-1 times

// Space Complexity: O(N). 3 arrays of size N


// Optimization
// Intuition:  While trying to optimize our code we must look out for repetitions. At the first glance, 
// we see that we are going through the key-value again and again to find the minimum edge weight that is 
// not part of the MST. Can we think of a data structure that stores the minimum weight at the top at any given instance?

// Approach: We would use a minimum heap to facilitate this task. Min-heap would contain the weight required to reach a 
// node along with its index. Here is a demonstration of the same.

// jsut replaced the forloop with the min priority queue
// rest all is same


int main(){
	int N=5,m=6;
	vector<pair<int,int> > adj[N]; 
	adj[0].push_back({1,2});
	adj[0].push_back({3,6});
	adj[1].push_back({0,2});
	adj[1].push_back({2,3});
	adj[1].push_back({3,8});
	adj[1].push_back({4,5});
	adj[2].push_back({1,3});
	adj[2].push_back({4,7});
	adj[3].push_back({0,6});
	adj[3].push_back({1,8});
	adj[4].push_back({1,5});
	adj[4].push_back({2,7});



	
	
    int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});

    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
	            key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
            
    } 
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}

// Time Complexity: O(NlogN). N iterations and logN for priority queue, where N is no of nodes

// Space Complexity: O(N). Three arrays and priority queue