//###################### Shortest Distance in undirected Graph with unit edges ############################
// We need to find shortest distnce from source node to all other nodes 
// so just simply apply bfs
// and maintain a pair in queue, where first element is node and second is distamce of that node from source
// that distamce is wqual to distance of node calling it + 1
// as soon as we find our node, we will return the distance 
// my approach works if we need to finf it for a destination node

// if we need to find for all node then
// r we could also have a distance array and perform operations using it 
// all values will be intialied to INT_MAX and source will have distance 0
// as you encounter other nodes update their distance by using min(dist[i], dist[node] + 1)
// that is minumum between value already present and 1 + distance of node from source which is calling node i

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

void BFS(vector<int> adj[], int N, int src) 
{ 
	int dist[N];
	for(int i = 0;i<N;i++) dist[i] = INT_MAX; 
	queue<int>  q;
	
	dist[src] = 0;
	q.push(src); 

	while(q.empty()==false) 
	{ 
		int node = q.front(); 
		q.pop();
		 
		for(auto it:adj[node]){
		    if(dist[node] + 1 < dist[it]){
		        dist[it]=dist[node]+1;
		        q.push(it);
		    }
		} 
	} 
	for(int i = 0;i<N;i++) cout << dist[i] << " "; 