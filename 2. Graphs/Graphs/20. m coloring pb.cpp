// Given an ubdirected graph and an integer M.
// Determine if graph can be colored with at most M colors such that no two adjacent vertices of grpah have same color
// using recursion, we willl try ball colors on all vertices
// as soon as I reach the first possible config, I return true
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

bool isSafe(int node, int color[], bool graph[101][101], int n, int col){
    // check if any of its adjacent nodes do not have the same color
    for(int k = 0; k < n; k++){
        if(k != node && graph[k][node] == 1 && color[k] == col){
            return false;
        }
    }
    return true;
}

bool solve(int node, int color[], int m, int N, bool graph[101][101]){
    // base condition
    if(node == N)
    {
        return true; // base case, we have covered all the nodes form 0 to N-1
    }
    for(int i = 1; i <= m; i++)
    {
        if(isSafe(node, color, graph, N, i)){
            // if its safe to assign the color, assign the same
            color[node] = i;
            // call on the next node
            //  if that return true, means base case was reached
            // simply keep on returtning as one config is possible
            if(solve(node + 1, color, m, N, graph))
            {
                return true;
            }
            // otherwise backtracj and choose another colour
            color[node] = 0;
        }
    }
    // if we werent able to assign any colour, then no config is possible
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    int color[V] = {0}; // array storing color of the nodes
    // our colors will range from 1 to m 1<= color <= m
    if(solve(0, color, m, V, graph))
    {
        return true;
    }
    return false;
}

