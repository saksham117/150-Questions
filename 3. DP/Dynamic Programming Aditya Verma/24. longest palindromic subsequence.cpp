// palindromic questions in itself are an entirely new category
// but still the parent question is lcs

// we shall be given a string as input and we have to output an integer

// the subsequence we are finding should be palindromic
// and we need to return its size

// for eg if the string is a g b c b a
// then the longet common subsequence is gonna be a b c b a

// now how does this question relaet with lcs
// 1) the output pattern is same(int in both cases)
// 2) in both we have been asked longest subsequence
// 3) only differnce is in input, we are given a single string whereas in that we were given two strings

// // so we can say that their is 2/3 matching
// // so we can approach it with lcs


// it is only this differnce in input where the answer lies
// since as input we have only one string, therefore we need to create another string
// now what can be that string
// that string can be the reverse of the string1

// so i have string1 and as string2, reverse of string1
// now the questin reduces to finding the lcs in betweent the two

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

    int longestPalinSubseq(string A) {
        //code here
        string s1 = A;
        reverse(A.begin(), A.end());
        string s2 = A;
        return getLongestSubsequence(s1,s2); 
    }
};
