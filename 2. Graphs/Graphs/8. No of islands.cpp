#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    //Function to find the number of islands.
    
    bool isValid(int x, int y, int rows, int cols, bool **visited){
        if(x >= 0 && x < rows && y >= 0 && y < cols && visited[x][y] == false){
            return true;
        }

        return false;
    }

    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    void dfs(vector<vector<char>>& grid, int x, int y, int rows, int cols, bool** visited){

        visited[x][y] = true;
        for(int i = 0; i < 8; i++){
            if(isValid(x+dx[i], y+dy[i], rows, cols, visited) && grid[x+dx[i]][y+dy[i]] == '1'){
                dfs(grid, x+dx[i], y+dy[i], rows, cols, visited);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        // Code here
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        bool** visited = new bool*[rows];
        for(int i = 0; i < rows; i++){
            visited[i] = new bool[cols];
            for(int j = 0; j < cols; j++){
                visited[i][j] = false;
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1' && visited[i][j] == false){
                    count+=1;
                    dfs(grid, i, j, rows, cols, visited);
                    
                } 
            }
        }

        return count;
    }
};