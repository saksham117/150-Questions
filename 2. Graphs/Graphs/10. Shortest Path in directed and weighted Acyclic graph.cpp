// 1) Find topological sort for this dag 
// 2) Create a distance array and mark distane of source as 0
// 3) We are gonna update distances of neighbours for each node and thode nodes will be taken from the topo sort 

// We coould do a simple bfs too, but in that there would be repeated calls to the same node
// That we are saving using topo sort

// For all who are wondering the intution behind Topological sorting and why haven't we use simple DFS or BFS 
// from the source node instead .
// READ THIS.................

// lets say you want to do it using DFS
// yes you can do it using DFS , but consider the case when you already updated a node's distance by a dfs() 
// call and lets say its 7 and as it is DFS then its obvious that you also have updated all the nodes in its segment of DFS call . 
// now you have reached to the same node from different dfs() call and now the distance is 4 , 
// so in order to update all the nodes which were affected by the DFS call previously on the node considering distance as 7 , 
// you now again have to do the same so that its updated with new min distance.
// Same is the scenario for the simple BFS approach.
// This multiple time calling DFS/BFS degrades the Time Complexity, hence Topological Ordering save you from that overhead as 
// you already know which nodes will come after the current node , so you keep on updating it .