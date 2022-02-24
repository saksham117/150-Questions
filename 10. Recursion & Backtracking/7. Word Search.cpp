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



class Solution {
public:
//     right down left up
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
//     check if indexes are valid or not
    bool isValid(int x, int y, int n, int m){
        if(x >= 0 && y >= 0 && x < n && y < m){
            return true;
        }
        
        return false;
    }
    
    bool helper(vector<vector<char>>& board, string word, int n, int m, int index, int x, int y){
        
//         base case
        if(index == word.length()){
            return true;
        }
        
        for(int i = 0; i < 4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if(isValid(newX, newY,n,m) && board[newX][newY] != '\0' && board[newX][newY] == word[index]){   
                char temp = board[newX][newY];
                board[newX][newY] = '\0';
                index += 1;

                bool ans = helper(board,word,n,m,index,newX,newY);
                if(ans){
                    return ans;
                }
                
                index -= 1;
                board[newX][newY] = temp;

            }
            
        }
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        int index = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[index]){
                    char temp = board[i][j];
                    board[i][j] = '\0';
                    index += 1;
                    
                    bool ans = helper(board,word,n,m,index,i,j);
                    if(ans == true){
                        return ans;
                    }
                    
                    board[i][j] = temp;
                    index -= 1;
                }
            }
        }
        
        return false;
        
    }
};