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

class Solution{
    public:
    // right, down, left, up
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    char dir[4] = {'R', 'D', 'L', 'U'};

    bool isValid(int x, int y, int n){
        if(x >= 0 && y >= 0 && x < n && y < n){
            return true;
        }
        return false;
    }

    void helper(vector<vector<int>> &m, int n, vector<string>& ans, bool** visited, int x, int y, string& path){

        if(x == n-1 && y == n-1 && m[x][y] == 1){
            ans.push_back(path);
            return;
        }

        for(int i = 0; i < 4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(isValid(newX, newY, n) && m[newX][newY] == 1 && visited[newX][newY] == false){
                path.push_back(dir[i]);
                visited[newX][newY] = true;
                helper(m,n,ans,visited,newX, newY,path);
                path.pop_back();
                visited[newX][newY] = false;
            }
        }

        return;

    }


    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;

        bool** visited = new bool*[n];
        for(int i = 0; i < n; i++){
            visited[i] = new bool[n];
            for(int j = 0; j < n; j++){
                visited[i][j] = false;
            }
        }

        string path = "";

        if(m[0][0] == 1){
            visited[0][0] = true; // this is what I usualyy forget to write, causin runtime erorr
            helper(m,n,ans,visited, 0,0,path);
        }

        sort(ans.begin(), ans.end());
        return ans;


    }
};