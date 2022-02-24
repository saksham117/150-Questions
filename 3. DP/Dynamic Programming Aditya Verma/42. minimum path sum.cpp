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


// no need to maintain visited vaise
// coz I can only go down and tight
// peeche to jaa hi nahi sakta

class Solution {
public:
    bool isValid(int x, int y, int n, int m){
        if(x >= 0 && y >= 0 && x < n && y < m){
            return true;
        }

        return false;
    }

    int helper(vector<vector<int>>& grid, int i, int j, bool** visited, int n, int m){

        if(i == n-1 && j == m-1){
            return grid[i][j];
        }

        int down = -1;
        int right = -1; 

        if(isValid(i+1, j, n, m) && !visited[i+1][j]){
            visited[i+1][j] = true;
            down =  grid[i][j] + helper(grid, i+1, j, visited,n,m);
            visited[i+1][j] = false;
        }

        if(isValid(i, j+1, n, m) && !visited[i][j+1]){
            visited[i][j+1] = true;
            right = grid[i][j] + helper(grid, i, j+1, visited,n,m);
            visited[i][j+1] = false;
        }

        if(right == -1){
            return down;
        }

        if(down == -1){
            return right;
        }

        return min(down,right);
    }


    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        if(n == 0){
            return 0;
        }
        int m = grid[0].size();

        if(m == 0){
            return 0;
        }

        bool **visited = new bool*[n];
        for(int i = 0; i < n; i++){

            
            visited[i] = new bool[m];
            for(int j = 0; j < m; j++){
                visited[i][j] = false;
            }

        }

        return helper(grid, 0, 0, visited, n, m);
    }
};

// just memoize it and ans will be accepted
// Writing bottom up approach is very simple
// thanks to aditya verma


// dp code
//  i coded this myself during revision
// complete solution is pretty simple
// howvere ek additioanl check lagega when i == 1 or j == 1
// when i = 1 khali right jaa sakte hain
// when j == 1 khali down jaa sakte hain
// to bus handle that case
// rest is easy coz of Adi bhaiya

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int** dp = new int*[n+1];
        for(int i = 0; i <= n; i++){
            dp[i] = new int[m+1];
            for(int j = 0; j <= m; j++){
                dp[i][j] = 0;
            }
        }
        
        for(int j = 1; j <= m; j++){
            dp[1][j] = dp[1][j-1] + grid[0][j-1];
        }
        
        for(int i = 1; i <= n; i++){
            dp[i][1] = dp[i-1][1] + grid[i-1][0];
        }
        
        for(int i = 2; i <= n; i++){
            for(int j = 2; j <= m; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
            }
        }
        
        return dp[n][m];
    }
};