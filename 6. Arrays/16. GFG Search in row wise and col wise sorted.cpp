// // but in gfg question The first integer of each row is may or may not be greater than the last integer of the previous row.
// the only thing is that rows are sorted and cols are sorted
// So gfg solution is in next video

// eg array is
//  10 20 30 40
//  15 25 35 45
//  27 29 37 48
//  32 33 39 50

// Brute Force
// takes O(N^2) time, basically iterate over complete matric and search

// Optimal Appraoch (nXm matrix)
// Start from top right corner, that is i = 0 and j = m-1

// We will compare this element with our key, which is say 29
// if that element is greater then, all element below that element in the same col will be greater than it
// so we cannot use the last col
// so we did j--

// if it is less than, we maintain j and do i++

// if key found, great return true
// as soon as i or j go out of bound, return -1
// key wont be found
// a simple algo, but so so so powerful

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
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    // your code here
        int i = 0;
        int j = M-1;

        while(i >= 0 && j >= 0 && i < N && j < M){
            if(mat[i][j] == X){
                return 1;
            }
            else if(mat[i][j] > X){
                j--;
            }
            else{
                i++;
            }
        }
	
        return 0;
    }
};