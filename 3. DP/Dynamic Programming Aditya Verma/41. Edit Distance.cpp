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

// s1 = ahellobye
// s2 = amezooe

// if the strings match at indexx i and j, do nothing and recursively call for i+1 and j+1 (where i is for str1 and j is for str2)
// if they do not match
// I can perform one of the three operation
// 1) insert
// 2) delete
// 3) replace

// If I replace, then both characters, i and j become equal, so now we increment i by one and j bye one 
// If i would have deleted, I would increment i by one and let j remain the same 
// If insert op, think of it like insertin at i-1, and then making a recursive call, keeping i the same and incrementing j by 1


// base case (I got this wrong)
// if i reach end of str1
// return str2.len() - j

// if i reach end of str2
// return str1.length() - i;


class Solution {
public:
    int helper(string word1, string word2, int i, int j){

        // base case
        if( i == word1.length()){
            return word2.length() - j;
        }

        if(j == word2.length()){
            return word1.length() - i;
        }

        if(word1[i] == word2[j]){
            return helper(word1, word2, i+1, j+1);
        }
        else {
            return min(1 + helper(word1, word2, i+1, j+1),  // replacement
                       min( 1 + helper(word1, word2, i+1, j), // deletion
                       1 + helper(word1, word2, i, j+1))); // insertion
        }


    }

    int minDistance(string word1, string word2) {
        
        if(word1.length() == 0){
            return word2.length();
        }

        if(word2.length() == 0){
            return word1.length();
        }
        
        return helper(word1, word2, 0, 0);
    }
};

// optimizing it using memoization
class Solution {
public:
    int helper(string word1, string word2, int i, int j, int**dp){

        // base case
        if( i == word1.length()){
            return word2.length() - j;
        }

        if(j == word2.length()){
            return word1.length() - i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(word1[i] == word2[j]){

            dp[i][j] = helper(word1, word2, i+1, j+1, dp);
            return dp[i][j];
        }
        else {
            dp[i][j] = min(1 + helper(word1, word2, i+1, j+1, dp),  // replacement
                       min( 1 + helper(word1, word2, i+1, j, dp), // deletion
                       1 + helper(word1, word2, i, j+1, dp))); // insertion

            return dp[i][j];
        }


    }

    int minDistance(string word1, string word2) {
        
        if(word1.length() == 0){
            return word2.length();
        }

        if(word2.length() == 0){
            return word1.length();
        }
        int**dp = new int*[word1.length() + 1];
        for(int i = 0; i <= word1.length(); i++){
            dp[i] = new int[word2.length() + 1];
            for(int j = 0; j <= word2.length(); j++){
                dp[i][j] = -1;
            }
        }

        return helper(word1, word2, 0, 0, dp);
    }
};

// Writing bottom up approach is very simple
// thanks to aditya verma
// link: https://leetcode.com/problems/edit-distance/discuss/25895/Step-by-step-explanation-of-how-to-optimize-the-solution-from-simple-recursion-to-DP
// yt: https://www.youtube.com/watch?v=tooMn-xfYCU

// i wrote this while revising
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        int** dp = new int*[n+1];
        for(int i = 0; i <= n; i++){
            dp[i] = new int[m+1];
            for(int j = 0; j <= m; j++){
                dp[i][j] = 0;
                
                if(i == 0){
                    dp[i][j] = j;
                }
                
                if(j == 0){
                    dp[i][j] = i;
                }
            }
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }
        
        return dp[n][m];
    }
};