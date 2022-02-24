#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// better solution exists
// no need to do dfs

class Solution {
public:

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool isValid(int x, int y, int n, int m)
    {
        if(x < 0 || x >= n || y < 0 || y >= m)
        {
            return false;
        }
        return true;
    }

    void helper(vector<vector<int>>& grid, int** visited, int n, int m, int& perimeter)
    {   
        int x = -1, y = -1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    x = i;
                    y = j;
                    break;
                }
            }
        }

        queue<pair<int,int>> q;
        q.push({x,y});

        while(!q.empty())
        {
            pair<int, int> cord = q.front();
            q.pop();

            int x = cord.first;
            int y = cord.second;
            visited[x][y] = 1;

            for(int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(isValid(newX, newY, n, m) && grid[newX][newY] == 1 && !visited[newX][newY])
                {
                    q.push({newX, newY});
                }
            }

            for(int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(!isValid(newX, newY, n, m))
                {
                    perimeter += 1;
                }
                else{
                    if(grid[newX][newY] == 0)
                    {
                        perimeter += 1;
                    }
                }
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int** visited = new int*[n];
        for(int i = 0; i < n; i++)
        {
            int* arr = new int[m];
            visited[i] = arr;
            for(int j = 0; j < m; j++)
            {
                visited[i][j] = 0;
            }
        }

        int perimeter = 0;
        helper(grid, visited, n, m, perimeter);
        return perimeter;
        
    }
};