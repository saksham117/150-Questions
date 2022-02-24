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

// Problem Statement: Given a weighted directed graph with negative edge weights with n nodes and m edges. 
// Nodes are labeled from 0 to n-1, the task is to find the shortest distance from the source node to all 
// other nodes. Output “-1” if there exists a negative edge weight cycle in the graph.
// Note: edges[i] is defined as u, v and weight.

// Why Djikstra’s doesn’t work?
// The answer is plain and simple. The presence of negative edge weights makes the situation dicey. Djikstra’s algorithm might 
// work in some cases and fail in some. Consider the following example:

// A - > B -> C 
// ^__________|            

// with edges being A B -1
//                  B C -4 
//                  C A -2

// Recall that in Dijkstra’s algorithm, we update the distance array every time we find a better solution which was a lesser
// distance. With the presence of negative edge weights, our algorithm would continue to update the distance array with lesser
// and lesser values and we might end up in time limit exceeded or segmentation fault error. Try to dry run the following 
// example and you would understand the issue yourself.


// Intuition: 
// We would try to update our distance array in a somewhat same manner as we did in Dijkstra’s algorithm. 
// However, we need to handle the negative edge weights as well. Thus, we need to update the array in a 
// controlled fashion may be, a specific number of times. Remember, we don’t want to end up in an endless loop.

// Approach
// 1) We would use a technique what is known as “Relaxing Edges” wherein we would update our distance array if we find a better 
// solution. We would do this N-1 times.We can relax the edges in any order.
// That does not matter


// 2) Now why N-1? Understand that for a given graph with N nodes, the maximum number of edges we could have between any two 
// nodes is N-1 in a single path. Moreover, our adjacency list might be in such a manner that only one node is updated in 
// a single pass. 
// Thus, to try out all nodes, we would require atleast N-1 iterations.
// The following is the demonstration of the same:

// See diagram in this link: https://takeuforward.org/data-structure/bellman-ford-algorithm-shortest-distance-with-negative-edge/

// Bellman ford Algo works for all cases, excpet when there is a negative edged cycle in the graph
// Another of its application is to find if the graph contains a negative cycle or not 

// Also note. Bellman works for directed graph in all cases except the above one
// For undirected graph however egde  1-2 means 1->2 and 2->1
// So in case of undirected graph, if we have any negative edge, bellman ford algo will detect is as a negative cycle and stop
// right there 


// So we need a distance array and initialize it just like in Dijkstras Algorithm

// Time Complexity: O(N*E). We check E edges N times  (N-1 times to precise)

// Space Complexity: O(N). Distance Array

struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

int main(){
    int N=6,m=7;
    vector<node> edges; // defining rhe edges of the graph
	edges.push_back(node(0,1,5));
	edges.push_back(node(1,2,-2));
	edges.push_back(node(1,5,-3));
	edges.push_back(node(2,4,3));
	edges.push_back(node(3,2,6));
	edges.push_back(node(3,4,-2));
	edges.push_back(node(5,3,1));

    // setting the source 
    int src=0;
    // defining infinty
    int inf = 10000000;

    // intializing the distance vector 
    vector<int> dist(N, inf); 
    dist[src] = 0; 

    // iterating over the edges one by one 
    // repeating the same thing N-1 times
    for(int i = 1;i<=N-1;i++) {
        for(auto it: edges) {
            if(dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt; 
            }
        }
    }

    // if after N-1 traversals, the distance of any vertex from any vertex still reduce
    // then there exists a negative cycle
    int fl = 0; 
    for(auto it: edges) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            cout << -1; 
            fl = 1; 
            break; 
        }
    }
    
    if(!fl) {
        for(int i = 0;i<N;i++) {
            cout << dist[i]<<" ";
        }
    }
    return 0;
}

// gfg code
class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int N, vector<vector<int>> edges, int src) {
        // Code here
        // defining infinty
        int inf = 10000000;

        // intializing the distance vector 
        vector<int> dist(N, inf); 
        dist[src] = 0; 

        // iterating over the edges one by one 
        // repeating the same thing N-1 times
        for(int i = 1;i<=N-1;i++) {
            for(auto it: edges) {
                if(dist[it[0]] + it[2] < dist[it[1]]) {
                    dist[it[1]] = dist[it[0]] + it[2]; 
                }
            }
        }

        return dist;

    }
};