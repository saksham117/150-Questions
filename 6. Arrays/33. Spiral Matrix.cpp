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
    bool check(int topRow, int bottomRow, int leftCol, int rightCol){
        if(topRow <= bottomRow && leftCol <= rightCol){
            return true;
        }
        return false;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;

        if(matrix.size() == 0){
            return ans;
        }
        int topRow = 0;
        int bottomRow = matrix.size() - 1;
        int leftCol = 0;
        int rightCol = matrix[0].size() - 1;

        while(topRow <= bottomRow && leftCol <= rightCol){

            // go right
            for(int i = leftCol; i <= rightCol; i++){
                ans.push_back(matrix[topRow][i]);
            }

            topRow += 1;

            if(!check(topRow, bottomRow, leftCol, rightCol)){
                break;
            }

            // go down
            for(int i = topRow; i <= bottomRow; i++){
                ans.push_back(matrix[i][rightCol]);
            }

            rightCol -= 1;
            if(!check(topRow, bottomRow, leftCol, rightCol)){
                break;
            }

            // go left
            for(int i = rightCol; i >= leftCol; i--){
                ans.push_back(matrix[bottomRow][i]);
            }

            bottomRow -= 1;
            if(!check(topRow, bottomRow, leftCol, rightCol)){
                break;
            }

            // go up
            for(int i = bottomRow; i >= topRow; i--){
                ans.push_back(matrix[i][leftCol]);
            }

            leftCol += 1;
        }

        return ans;

        
    }
};