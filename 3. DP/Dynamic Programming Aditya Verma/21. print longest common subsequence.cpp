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
// now instead of returning the size of the lcs we need to return the lcs itself
// workflow will be that we shall fill the array t according to lcs
// after that we can say we would backtrack to obtain the string
// we shall start from the laste element (t[m][n])
//so we will start from t[m][n]
// i = m
// j = n
// if a[i-1] === b[j-1]
// then we would include that elemnt in our final string
// and decrement both i and j

// // if a[i-1] != b[j-1]
// then we shall backtrack to that index where value is greatest
// if t[i-1][j] >= t[i][j-1]
// then decrement i and j remains same
// else
// derement j and i remains the same


// call lcs first so that the table is generetaed
// now once the table is generetaed do the following steps
// to print and store the lcs



class Solution {
  public:
    string getLongestSubsequence(string A, string B) {
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

        // so now lets try to construct the lcs

        string s = "";
        int i = n;
        int j = m;

        while(i > 0 && j > 0)
        {
            if(A[i-1] == B[j-1])
            {
                s.push_back(A[i-1]);
                i--;
                j--;
            }
            else
            {
                if(dp[i][j-1] > dp[i-1][j])
                {
                    j--;
                }
                else
                {
                    i--;
                }
            }
        }
        reverse(s.begin(), s.end());
        return s;

    }
};

// Printing longest common string would be more simpler
// just go to the index having max value
// and keep on going dogonally up in left direction till the condition A[i-1] == B[j-1]
// and you will get thhe string