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

// we will be given two strings
// string a and string b

// we need to convert string a to string b
// for eg a = heap
// b = pea

// so for changing from heap to pea
// we involve one insertion of p and two deletions of h and p


// now how to think that this is a question of lcs
// whenever we are given two strings, and we need to find something optimal, then it is a question of lcs

// so got the funda
// if length of string1 is m
// length of string 2 is n

// length of longest common subsequence is l

// then no of insertins = n-l
// then no of deletions = m-l


// that is it
// you can see for yourself

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

	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
        int lcs = getLongestSubsequence(str1,str2);
        int deletions = str1.length() - lcs;
        int insertions = str2.length() - lcs;
        return insertions + deletions;
	    
	} 
};