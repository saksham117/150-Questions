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

// coded all this by myself
class Solution {
public:
    
    bool isValid(int x, int y, int n, int** board){
        
//         first checking is seomthing present in the same col
        for(int i = 0; i < n; i++){
            if(board[i][y] == 1){
                return false;
            }
        }
        
        
//         check along the primary diagonal in +ve direction
        int i = x+1;
        int j = y+1;
        
        while(i < n && j < n){
            if(board[i][j] == 1){
                return false;
            }
            i++;
            j++;
        }
        
//         check along the primary diagonal in -ve direction
        
        i = x -1;
        j = y -1;
        
        while(i >= 0 && j >= 0){
            if(board[i][j] == 1){
                return false;
            }
            i--;
            j--;
        }

//         check along the secondary diagonal in +ve direction
        i = x+1;
        j = y-1;
        
        while(i >= 0 && j >= 0 && i < n && j < n){
            if(board[i][j] == 1){
                return false;
            }
            i++;
            j--;
        }
//         check along the secondary diagonal in -ve direction
    
        i = x-1;
        j = y+1;
        
        while(i >= 0 && j >= 0 && i < n && j < n){
            if(board[i][j] == 1){
                return false;
            }
            i--;
            j++;
        }
        
        
        
        return true;
    }
    
    void helper(vector<vector<string>>& config, int** board, int queen, int n){
        
//         base case
        if(queen == n){
            vector<string> answer;
            for(int i = 0;i < n; i++){
                string row = "";
                for(int j= 0; j < n; j++){
                    if(board[i][j] == 1){
                        row += 'Q';
                    }
                    else{
                        row += '.';
                    }
                }
                answer.push_back(row);
            }
        
            config.push_back(answer);
            return;
        }
        
        
        for(int j = 0; j < n; j++){
            if(isValid(queen,j,n,board)){
                board[queen][j] = 1;
                helper(config,board,queen+1,n);
                board[queen][j] = 0;
            }
            else{
                continue;
            }
        }
        
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        int** board = new int*[n];
        for(int i = 0;i < n; i++){
            board[i] = new int[n];
            for(int j= 0; j < n; j++){
                board[i][j] = 0;
            }
        }
        
        vector<vector<string>> config;
        
        helper(config,board,0,n);
        
        return config;
    }
};

// I checked along the diagonals 2 extra time
// the thing is that we do not need to check along the primary and secondary diaginal in the downwards dir(+ve direction)
// this is becasue we are filling queens from row 0 to row n
// so if i am on row i,I only need to che for rows < i
class Solution {
public:
    
    bool isValid(int x, int y, int n, int** board){
        
//         first checking is seomthing present in the same col
        for(int i = 0; i < n; i++){
            if(board[i][y] == 1){
                return false;
            }
        }
        
        
//         check along the prinary diagonal in -ve direction     
        int i = x -1;
        int j = y -1;
        
        while(i >= 0 && j >= 0){
            if(board[i][j] == 1){
                return false;
            }
            i--;
            j--;
        }
        

//         check along the secondary diagonal in -ve direction     
        
        i = x-1;
        j = y+1;
        
        while(i >= 0 && j >= 0 && i < n && j < n){
            if(board[i][j] == 1){
                return false;
            }
            i--;
            j++;
        }
        
        
        
        return true;
    }
    
    void helper(vector<vector<string>>& config, int** board, int queen, int n){
        
//         base case
        if(queen == n){
            vector<string> answer;
            for(int i = 0;i < n; i++){
                string row = "";
                for(int j= 0; j < n; j++){
                    if(board[i][j] == 1){
                        row += 'Q';
                    }
                    else{
                        row += '.';
                    }
                }
                answer.push_back(row);
            }
        
            config.push_back(answer);
            return;
        }
        
        
        for(int j = 0; j < n; j++){
            if(isValid(queen,j,n,board)){
                board[queen][j] = 1;
                helper(config,board,queen+1,n);
                board[queen][j] = 0;
            }
            else{
                continue;
            }
        }
        
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        int** board = new int*[n];
        for(int i = 0;i < n; i++){
            board[i] = new int[n];
            for(int j= 0; j < n; j++){
                board[i][j] = 0;
            }
        }
        
        vector<vector<string>> config;
        
        helper(config,board,0,n);
        
        return config;
    }
};