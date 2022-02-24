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
// as input we shall be given two strings
// eg  a b c d g h
//     a b e d f h r

// so longest common subsequence for these will be 
// a b d h
// so in output we have to print the length of this subssequence

// subsequence can be discontinous, but susbtring has to be continous

// so lc susbtring would be ab

// let string a be of length n
// and let string b be of length m



// recursive Approach

// we shall start comparing from the last element onwards
// if the last element matches, then we increment by one and call on both the strings with size reduced by 1
// however if the last element do not match
// then we have two choices
// eeither reduces string1 by one and call on string2 or reduces string2 by 1 and call on string 1

class Solution {
  public:
    int helper(string A, string B, int n, int m){
        // base case
        if(n == 0 || m == 0){
            return 0;
        }

        // if indices match
        if(A[n-1] == B[m-1]){
            return 1 + helper(A,B,n-1,m-1);
        }
        else{
            return max(helper(A,B,n-1,m), helper(A,B,n,m-1));
        }

    }

    int getLongestSubsequence(string A, string B) {
        // code here
        int n = A.length();
        int m = B.length();

        return helper(A,B,n,m);
    }
};

// Memoization
class Solution {
  public:
    int helper(string A, string B, int n, int m, int** matrix){
        // base case
        if(n == 0 || m == 0){
            return 0;
        }

        // if problem already solved
        if(matrix[n][m] != -1){
            return matrix[n][m];
        }

        // if indices match
        if(A[n-1] == B[m-1]){
            matrix[n][m] =  1 + helper(A,B,n-1,m-1, matrix);
            return matrix[n][m];
        }
        else{
            matrix[n][m] = max(helper(A,B,n-1,m, matrix), helper(A,B,n,m-1, matrix));
            return matrix[n][m];
        }

    }

    int getLongestSubsequence(string A, string B) {
        // code here
        int n = A.length();
        int m = B.length();

        int **matrix = new int*[n+1];
        for(int i = 0; i <= n; i++){
            matrix[i] = new int[m+1];
            for(int j = 0; j<=m; j++){
                matrix[i][j] = -1;
            }
        }

        return helper(A,B,n,m, matrix);
    }
};

// dynamic programming 
class Solution {
  public:
    int getLongestSubsequence(string A, string B) {
        // code here

        int n = A.length();
        int m = B.length();

        int **dp = new int*[n+1];

        for(int i = 0; i <= n; i++){
            dp[i] = new int[m+1];

            for(int j = 0; j <= m; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = -1;
                }
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){

                if(A[i-1] == B[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];

    }
};

