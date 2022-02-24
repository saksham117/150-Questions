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

// learnt one new thing
// set<pair> is defined but unordered_set<pair> is not defined
// very simple algo
// Computer Graphics main bhi kar rakha hai yeh


class Solution {
public:
    bool isValid(int x, int y, int n, int m){
        if(x >= 0 && y >= 0 && x < n && y < m){
            return true;
        }

        return false;
    }

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    void helper(vector<vector<int>>& image, int sr, int sc, int newColor, set<pair<int,int>>& visited, int n, int m){

        int color = image[sr][sc];
        image[sr][sc] = newColor;
        visited.insert({sr,sc});

        for(int i = 0; i < 4; i++){

            int newX = sr + dx[i];
            int newY = sc + dy[i];

            pair<int,int> coord(newX, newY);

            if(isValid(newX, newY, n, m) && image[newX][newY] == color && visited.count(coord) == 0){
                helper(image, newX, newY,  newColor, visited, n, m);
            }
        } 
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int n = image.size();
        int m = image[0].size();
        set <pair<int,int>> visited;
        helper(image,sr,sc,newColor,visited,n,m);
        return image;
    }
};