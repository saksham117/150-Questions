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

// we would be given two strings
// let us say       a b c d e
// and the other is a b f c e

// the lcs for the above is abce
// but the longest common substring should be continous and that is ab

// we need to output the length of the longest common substring
// initialization is exactly as same as that of LCS

// over here if the elements are equal, then we include both of them and move ahead after incrementing by one
// however if the elements are not equal then, we simply make it zero

// After that we simply cannot return matrix[n][m]
// we have to return the max value in the matrix and not t[m][n]. Just traverse through the matrix once and 
// store max value in a variable and return that. Why it is so? Cuz substring can exist anywhere in between. 
// Just think a bit about it bit and you will understand.(draw matrix for the above example only)
// matrix[m][n] represents it represents longest common substring ending at n-1th char in s1 & m-1th char in s2. 
// So that's why maximum can be in the matrix

class Solution{
    public:
    
    int longestCommonSubstr (string A, string B, int n, int m)
    {
        // your code here

        int maximum = INT_MIN;

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
                    dp[i][j] = 0;
                }

                if(dp[i][j] > maximum){
                    maximum = dp[i][j];
                }
            }
        }

        return maximum;
    }
};