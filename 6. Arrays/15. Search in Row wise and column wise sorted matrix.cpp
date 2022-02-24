// This loooks daunting, but is easy as cake

// Brute Force
// takes O(N^2) time, basically iterate over complete matric and search

// Optimized way
// so think of this 2d matrix(NXM), where N is no of rows and M is no of cols 
// as a 1d array, where index start from 0 and last index = NXM-1, ie total no of elements is NXM

// Now do normal binary serach as earlier
// when we find a mid, we need to check if its present in this 2d matrix or not

// so for that
// our row index = mid/M 
// our col index = mid%M

// As simple as that
// leetcode question
// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.


// // but in gfg question The first integer of each row is may or may not be greater than the last integer of the previous row.
// the only thing is that rows are sorted and cols are sorted
// So gfg solution is in next video

// leetcode solution

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
    int N; // number of rows
    int M; // number of columns
    
    bool binarySearch(vector<vector<int>>& matrix, int key, int low, int high)
    {
        if(low > high)
        {
            return false;
        }
        
        
        int mid = (low + high)/2;
        
        int x = mid/M;
        int y = mid%M;
        
        if(matrix[x][y] == key)
        {
            return true;
        }
        
        else if(matrix[x][y] > key)
        {
            return binarySearch(matrix,key,low,mid-1);
        }
        
        else
        {
            return binarySearch(matrix,key,mid+1,high);
        }
        
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size() == 0)
        {
            return false;
        }
        
        N = matrix.size();
        M = matrix[0].size();
        
        int high = N*M -1;
        int low = 0;
        
        bool ans = binarySearch(matrix,target,low,high);
        return ans;
    }
};

