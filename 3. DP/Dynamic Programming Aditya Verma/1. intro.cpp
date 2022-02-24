// First is to identify, whether a question is of dynamic programming or not

// Dynamic Programmin is nothing but enhanced recursion
// so if a problem can be solved by recursion, then it can even be solved by dynamic programming

// solving via recursion and memoization is top to down approach (as we go from bigger subproblem to solve smaller subproblem)
// dynamic programming is bottom to top as we build for smaller solutions and then we move up

// ################# 2 MAIN CHARACTERISTICS OF DP ###################
//  1) dp always asks for some optimal solution/ result.
// 2.) in the problem we are given a choice, whether to include this element or whether to not include this element

// ################# For example ###################

// like knapsack involves recursion
// and if it involves recursion and is an overlapping problem, then it is a question of dp
// if the recursive function is making two calls, then somewhere or the other there is a 
// probability that dynamic prgramming will be involved
// second thing will be optimal will be asked. Largest, minimum, maximum all these things shall be asked

// so the approaach to solve would be to go for recursive function, then memoize it and finally look for dp solutiion
// do not straightawy go for a dp solution

// Interesting Observation
// So one of the problems, ie Coin Change Problem
// In that if the curreny array is an array such that we have 3 indices i,j,k where i<j<k
// then arr[i] + arr[j] < arr[k]
// Then only Greedy Approach can work
// Otherwise it will be a problem of DP



// Categories
// 1) 0-1 knapsack
// 2) Unbounded knapsack
// 3) Fibonnaci
// 4) LCS
// 5) LIS (LONGEST INCREASING Subsequence)
// 6) Kadanes Algorithm
// 7) Matrix Chain Multiplication
// 8) DP on trees
// 9) Dp on grids
// 10) others