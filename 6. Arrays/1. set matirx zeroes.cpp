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

// Approach 1
// Brute force approach: 
// Create a vector of pairs, and in 1st traversal, store all indexex where we have a zero
// Then once we have this, we will iterate over this vector of pairs and using it set rows and columns of matruix to zero in 
// O(NXM) time
// Time O(NXM) Space O(NM) 

// Approach 2
// Better force
// Whenever you encounter a zero, start two O(N) loops
// set that entire row to -1, except the places where it is already zero
// this is necessary because if we set some unvisited to 0, here itself, then when we traverse the matrix forward
// the rows and coulmns that were going to be set to zero by that 0, wont be set any more
// so only set non zero values to -1

// Then once this is fininshed, traverse the matrix again and wherever there is a -1, we set that to zero

// We are setting the terms to -1, becasue we have asked the interviewer that -1 is not a valid input
// Time O(NXM X (N+M)) Space O(1)

// Approach 3 (BETTER)
// Take two dummy arrays rows and cols 
// where row is of size m and col is of size n
// If we encounter a zero at index [i,j] set rows[i] and cols[j] = 1
// After traversing matrix one by one. Traverse matrix again O(NXM) and set each row and set each col to zero wherever there is a one in rows and cols array 
// Space is (O(N+M)) Time O(NXM + NXM)

// Approach 4 (BEST)
// Now in this approach, we will take the dummy arrays within our 2D matrix itself. 
// we take the first row as column dummy matrix
// and first column as row dummy matrix
// draw the matrix and you will see why (pretty obvious)

// take 2 variable  colflag and rowflag. intially marked as false 



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // variables to check if there are any 1 
        // in first row and column 
        bool row_flag = false;
        bool col_flag = false; 

        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                // updating the first row and col if 1  is encountered 
                if(i == 0 && matrix[i][j] == 0){
                    row_flag = true;
                }

                if(j == 0 && matrix[i][j] == 0){
                    col_flag = true;
                }

                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Modify the input matrix mat[] using the 
        // first row and first column of Matrix mat 
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){

                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        // modify first row if row_flag
        if(row_flag){
            for(int j = 0; j < cols; j++){
                matrix[0][j] = 0;
            }
        }

        // modify first col if col_flag
            for(int i = 0; i < rows; i++){
                matrix[i][0] = 0;
            }
        }

    
};