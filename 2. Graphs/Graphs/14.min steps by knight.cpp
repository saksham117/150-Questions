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

// Approach: 
// This problem can be seen as shortest path in unweighted graph. 
// Therefore we use BFS to solve this problem. We try all 8 possible positions where a Knight can reach from its position. 
// If reachable position is not already visited and is inside the board, we push this state into queue with distance 1 more than its 
// parent state. ( I used a different technique that I have learnt from striver.) 
// Finally we return distance of target position, when it gets pop out from queue.

// Below code implements BFS for searching through cells, where each cell contains its coordinate and distance from starting node. 
// In worst case, below code visits all cells of board, making worst-case time complexity as O(N^2) 

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};


    bool isValid(int x, int y, int N){
        
        if(x >= 1 && x <= N && y >= 1 && y <= N)
        {
            return true;
        }

        return false;
    }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    
	   // creating and intializing the visited array
	    bool** visited = new bool*[N+1];
	    for(int i = 0; i <= N; i++){
	        visited[i] = new bool[N+1];
	        for(int j = 0; j <= N; j++){
	            visited[i][j] = false;
	        }
	    }
	
	    queue<pair<int,int>> q;
	    pair<int,int> source = {KnightPos[0], KnightPos[1]};
	    q.push(source);
	    visited[source.first][source.second] = true;
	    
	    int steps = 0;
	    
	    while(!q.empty()){
	        
	        int size = q.size(); // instead of having another distance paramter to keep a trcak of distance using its parents distance
            // I have used the concept I learn in tree series from Striver
	        
	        for(int i = 0; i < size; i++){ 
	            
	            pair<int, int> curr = q.front();
	            int currX = curr.first;
	            int currY = curr.second;
	            q.pop();
	            
	            for(int i = 0; i < 8; i++){
	                
	                int newX = currX + dx[i];
	                int newY = currY + dy[i];
	                
	                if(isValid(newX, newY, N) && !visited[newX][newY]){
	                    
	                    if(newX == TargetPos[0] && newY == TargetPos[1]){
	                        return steps + 1;
	                    }
	                    
	                    q.push({newX, newY});
	                    visited[newX][newY] = true;
	                }
	            }
	        }
	        
	        steps += 1;
	    }
	    
	    return 0;
	    
	}
	
	
};