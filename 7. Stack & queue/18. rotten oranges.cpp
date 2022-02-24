#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>


using namespace std;

// Normal BFS 
// this is my code but muchj more optimized
// used dx, dy
// maintained a varaible t intialized as -1 to keep track of time
// when making O(n^2) traversal to find intial rotton oranges, also storing number of fresh oranges
// this saves one extra traversal of O(N^2) to see if all fresh oranges are rotten or not

// this is the code I wrote
class Solution {
public:
//     right down left up
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    bool isValid(int x, int y, int n, int m){
        if(x >= 0 && y >= 0 && x < n && y < m){
            return true;
        }
        
        return false;
    }
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size(); // rows
        int m = grid[0].size(); // cols
        
        queue<pair<int, int>> q;
        int freshOranges = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                
                if(grid[i][j] == 1){
                    freshOranges++;
                }
            }
        }
        
        cout<<freshOranges<<'\n';

        
        int time = 0;
        
        while(!q.empty() && freshOranges > 0){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                auto p  = q.front();
                int x = p.first;
                int y = p.second;
                q.pop();
                
                for(int j = 0; j < 4; j++){
                    
                    int newX = x + dx[j];
                    int newY = y + dy[j];
                    
                    if(isValid(newX, newY, n, m) && grid[newX][newY] == 1){
                        freshOranges--;
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                    }
                }
            }
            
            time += 1;
        }
        
        cout<<freshOranges<<'\n';
        if(freshOranges == 0){
            return time;
        }
        else{
            return -1;
        }
        
        
    }
};


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        
        vector<int> dir={-1,0,1,0,-1}; //used for finding all 4 adjacent coordinates
        
        int m=grid.size();
        int n=grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh=0; //To keep track of all fresh oranges left
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    fresh++;
            }
        int ans=-1; //initialised to -1 since after each step we increment the time by 1 and initially all rotten oranges started at 0.
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                pair<int,int> p=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int r=p.first+dir[i];
                    int c=p.second+dir[i+1];
                    if(r>=0 && r<m && c>=0 && c<n &&grid[r][c]==1)
                    {
                        grid[r][c]=2;
                        q.push({r,c});
                        fresh--; // decrement by 1 foreach fresh orange that now is rotten
                    }
                    
                }
            }
            ans++; //incremented after each minute passes
        }
        if(fresh>0) return -1; //if fresh>0 that means there are fresh oranges left
        if(ans==-1) return 0; //we initialised with -1, so if there were no oranges it'd take 0 mins.
        return ans;
        
    }
};