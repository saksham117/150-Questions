// we would be given two strings a and b
// and we  have to merge them in such a way that we get both the strings

// for eg s1 = "geek"
// 	eg s2 = "eke"

// output colud be geekeke or geeke
// but we would prefer geeke because it is the shortest amongst the two


// they can be present discontinously as we can see in the next example
// a :  A G G T A B
// b:   G X T X A Y B

// ANS COULD BE A G G T G X A B T X A Y B
// BUT THE SHORTEST WILL BE A G G X T X A Y B


// SO ONE THING THAT WE Can observe is that if we just give the worst answer without thinking, then the answer would be 
// string a + string b
// and in both of them some letters would be common. Those common letters represent the longext common subsequence
// so from length of string a and length of string b, we subtract the length of lcs
// that would be our answer
// simple!!

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
class Solution
{
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
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        int lcs = getLongestSubsequence(X, Y);
        return m+n-lcs;
    }
};