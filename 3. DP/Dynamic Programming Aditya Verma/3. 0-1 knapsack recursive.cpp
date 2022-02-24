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

// as input we would be given weight array, value array and W
// output is maximum profit with the given constraint of weight
// for figuring out the base condition, think of the smallest valid input

// RECURSIVE Approach
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       if(W == 0 || n == 0){
           return 0;
       } 

       if(wt[n-1] <= W){
        //    either include the element or do not
           return max( val[n-1] + knapSack(W - wt[n-1], wt, val, n -1), knapSack(W, wt, val, n -1));
       }
       else{
           return knapSack(W, wt, val, n -1);
       }
    }
};


// Memoization Approach
// the array that we make, is made of rows and colums consisting of only those parameters that change
// so over here t will be [n+1][W + 1] matrix
class Solution
{
    public:
    int helper(int W, int wt[], int val[], int n, int** matrix){

        // base case
        if(W == 0 || n == 0){
           return 0;
       } 

    //    if subproblem already explored, no need to solve it again
       if(matrix[n][W] != -1){
           return matrix[n][W];
       }
       
    //    if weight of current element is less than the remaining capacity of the knapsack
       if(wt[n-1] <= W){
            // either include the element or do not
           int profit = max( val[n-1] + helper(W - wt[n-1], wt, val, n-1, matrix), helper(W, wt, val, n -1, matrix));
           matrix[n][W] = profit;
           return profit;
       }
       else{
           int profit =  helper(W, wt, val, n -1, matrix);
           matrix[n][W] = profit;
           return profit;
       }
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // intializing the memoization matrix    
       int** matrix = new int*[n+1];
       for(int i = 0; i <= n; i++){
           matrix[i] = new int[W + 1];
           for(int j = 0; j <= W; j++){
               matrix[i][j] = -1;
           }
       }

       return helper(W,wt,val,n,matrix);




       
    }
};

// so memoiztion is pretty simple
