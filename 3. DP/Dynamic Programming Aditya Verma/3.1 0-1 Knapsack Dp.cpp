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

// Recursive Approach for Reference
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


// DYNAMIC PROGRAMMING Approach
// only problem with memoized approach is that when we make repeated function calls, then it can be the case that the 
// memory stack get filled completely due to repeated calls and that might cause stack overflow
// however this problem occured in only one question and that was scrambled string(leetcode hard)
// a variation of matrix chain multiplication problems

// so in dp approach also called tabulation we need to make a table
// for that table the dimensions will be [n+1][W+1]
// the parameters that are changing + 1

// to fill the table we follow two steps
// 1) initialization
// 2) filling the table over iterations

// lets see what the individual cells of this matrix represent

// example
// weight array [1, 3, 4, 5]
// value array [1, 4, 5, 7]
// Capacity = 7
// n = 4

// matrix[n+1][w+1] = matrix[5][8] ~ Our matrix

// so matrix[2][3] will represent that if we are given the first two elements and the capacity of knapsack is 3, 
// what is the maximum value of profit

// matrix[3][6] will represnt that if we are given the first three elements and the capacity of knapsack is 6, 
// what is the maximum value of profit
//wt[1,3,4], val[1,4,5]


//finalyy t[4][7] will reperesnt that if we are goven all four weights than what is the maximum profit for knapsack capacity of 7
// and this shall be our answer
// so in this approach we alwasy return matrix[n][W]


// so in dp we convert the whole recursive process into a iterative process
// so the base case in recursion gets converted to the initialization step in dynamic programming !! Important
// so tis clearly points to the importance of recursion
// if we have thought of it using recursion then memoization is a piece of cake
// and so is dp as we are in fact seeing

// so for recursion the base case was 

// if(n == 0 || W == 0)
// {
// 	return 0;
// }

// so this is what we are going to do
// initializae the first row and first column to zero

// and now coming to the recursive calls part
// the recursive function gets converted to matrix
// and the changes are reflected by changes in i and j (so n, w are represented by i and j)

// so final code becomes
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int** matrix = new int*[n+1];

       for(int i = 0; i <= n; i++){

           matrix[i] = new int[W + 1];
           for(int j = 0; j <= W; j++){

                // this is the base case or as we would say intialization   
               if(i == 0 || j == 0){
                   matrix[i][j] = 0;
               }
               else{
                   matrix[i][j] = -1;
               }
           }
       }

        // iteratively filling the matrix from bottonm to up
       for(int i = 1; i <= n; i++){
           for(int j = 1; j <= W; j++){
            //    if weight of ith element is actually less than current capacity j then we have 2 options
               if(wt[i-1] <= j){
                   matrix[i][j] = max(val[i-1] + matrix[i-1][j - wt[i-1]], matrix[i-1][j]);
               }
               else{
                   matrix[i][j] = matrix[i-1][j];
               }
           }
       }

       return matrix[n][W];
    }
};
