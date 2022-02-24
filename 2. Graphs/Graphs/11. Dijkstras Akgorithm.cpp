// In the past, we were able to use breadth-first search to find the shortest paths between a source
// vertex to all other vertices in some graph G. The reason it worked is that each edge had equal
// weight (e.g., 1) so the shortest path between two vertices was the one that contained the fewest
// edges. Now, we introduce edge weights so the cost of traveling through edges can differ from
// edge to edge. The shortest path between two vertices is defined to be the path whose sum of edge
// weights is the least. BFS will not work on weighted graphs since the path with the fewest edges
// may not be the shortest if the edges it contains are expensive

// BFS will take longer since it does not follows the greedy method of choosing the shorter path, 
// so you will end up pushing any node a number of times into the queue actually.. which will end up taking a lot of time, 
// over here, you always start with the shortest node reachable and then try to move ahead..

// Now again we will be given a src node and we need to figure out shortest distance of all nodes from src node

// Algorithm
// First we will have a priority queue
// Priority queue will be of type pair, where pair is <dist,node>, and it will be a minHeap
// and the extra thing which we will be requiring is a distance array of size equal to no of vertices 

// make distance of source node as zero and push that pair into our pq
// so now using this, implement a bfs kind of algo
// update distance if the new distance is less than the older distance
// for a node, whose distance is already updated from infity, push it back into the queue, only when its distance is updated again
// /say node a had distance 10
// now it becomes 5
// so push it back to pq
// however if isntead of 5, we had 15, no need to push it back to pq 

// ITS IS A GREEDY ALGORITHM 
// We use a pq
// no need to maintain visited
// again using some sort of bfs traversal

// It can be applied to both directed as well as undirected graphs. Here is why:

// An undirected graph is basically the same as a directed graph with bidirectional connections 
// (= two connections in opposite directions) between the connected nodes.

// So you don't really have to do anything to make it work for an undirected graph. You only need 
// to know all of the nodes that can be reached from every given node through e.g. an adjacency list.

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include <utility>

using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > minHeap; // to greedily select the node
        // having minimum distance each time
        
        vector<int> distance (V);
        for(int i = 0; i < V; i++){

            distance[i] = INT_MAX;
        }

        minHeap.push({0,S}); // creating the enteries for the source vertex
        distance[S] = 0;

        while(!minHeap.empty()){

            auto p = minHeap.top();
            minHeap.pop();

            int node = p.second; // second element of pq pair is the node
            int distanceNode = p.first; // first element represents distance of 

            for(int i = 0; i < adj[node].size(); i++){

                auto p2 = adj[node][i]; // selecting the neighbour
                int newNode = p2[0]; // extracting the node
                int distanceNewNode = p2[1]; //extracting nodes distance from its parent

                if(distance[newNode] > distanceNode + distanceNewNode){ // if this new distance of distance of 
                // parent node from source + distance of newNode from parent is less than distance of newNode from source
                // then update it and send it to PQ
                    distance[newNode] = distanceNode + distanceNewNode;
                    minHeap.push({distance[newNode], newNode });
                }
                else{
                    continue;
                }
            }
        }

        return distance;
    }
};

// Notes: 
// 1) The code calculates the shortest distance but doesn’t calculate the path information. 
// We can create a parent array, update the parent array when distance is updated (like prim’s implementation) 
// and use it to show the shortest path from source to different vertices.

// 2) The code is for undirected graphs, the same Dijkstra function can be used for directed graphs also.

// 3) The code finds the shortest distances from the source to all vertices. 
// If we are interested only in the shortest distance from the source to a single target, 
// we can break the for loop when the picked minimum distance vertex is equal to the target (Step 3.a of the algorithm).

// 4) Time Complexity of the implementation is O(V^2). If the input graph is represented using adjacency list, 
// it can be reduced to O(E log V) with the help of a binary heap. Please see 
// Dijkstra’s Algorithm for Adjacency List Representation for more details.
// Time Complexity: O((N+E)*logN). Going through N nodes and E edges and log N for priority queue
// for fi=urther on time compexity : https://stackoverflow.com/questions/26547816/understanding-time-complexity-calculation-for-dijkstra-algorithm

// 5) Dijkstra’s algorithm doesn’t work for graphs with negative weight cycles. 
// It may give correct results for a graph with negative edges but you must allow a vertex 
// can be visited multiple times and that version will lose its fast time complexity. 
// For graphs with negative weight edges and cycles, Bellman–Ford algorithm can be used, 
// we will soon be discussing it as a separate post.


// Sample Input for gfg  
// 9 28
// 0 1 4
// 0 7 8
// 1 0 4
// 1 2 8
// 1 7 11
// 2 1 8
// 2 3 7
// 2 8 2
// 3 2 7
// 3 4 9
// 3 5 14
// 4 3 9
// 4 5 10
// 2 5 4
// 5 3 14
// 5 4 10
// 5 2 4
// 5 6 2
// 6 7 1
// 6 5 2
// 6 8 6
// 7 0 8
// 7 1 11
// 7 8 7
// 7 6 1
// 8 2 2
// 8 6 6
// 8 7 7
// 0

