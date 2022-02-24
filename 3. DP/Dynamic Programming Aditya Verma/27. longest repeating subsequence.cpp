// for eg id the string is A A B E B C D D
// THEN REPEATING SUBSEQUENCE IS A B D
// THIS IS ALSO THE LARGEST SUBSEQUENCE WHICH IS REPEATING
// CHARACTERS ONCE TAKEN, CANT BE USED AGAIN
// EG A AT INDEX 0, B AT INDEX 2 AND D AT INDEX 6 CAN ONLY BE CONSIDERED ONCE
// SO WE HAVE TO FIND THE LARGEST REPEATING SUBSEQUENCE

// WE HAVE TO RETURN THE LENGTH OF THE SUBSEQUENCE


//BASICALLY WE CAN RELATE IT WITH LCS
// HERE WE SHALL GENERATE A SECOND STRING WHICH IS GOING TO BE EQUAL TO THE FIRST STRING
// IN THE LONGEST REPEATING SUSBEQUENCE, ONLY THOSE ELEMENTS WILL COME WHICH APPEAR MORE THAN ONCE AND IN THE CORRECT ORDER
// SO ALL REPEATING ELEMENTS WILL COME AT MORE THAN ONE INDEX
// ONLY THOSE ELEMENTS WHICH APPEAR ONCE WILL COME AT THE EXACTLY SAME INDEX IN BOTH STRINGS
// I == J

// Now since we have stated that indices used once, cannot be used again to create another subsequence
// so if we find two characters that are repeating, then they can be a part of lcs (say index x1,x2)
// but we will only consider them if in the two strings we find that element at (x1, x2) and not in x1,x1 and x2,x2
// because again, we cannot reuse the indices

// ONLY CHANGE WILL BE THE ADDITIN OF THE CONDITION I != J
// so the problem is tough, but thinking it like this does help a lot

// if(a[i-1] == b[j-1] && i != j)
// {
// 	t[i][j] = 1 + t[i-1][j-1];
// }
// else
// {
// 	t[i][j] = max(t[i-1][j], t[i][j-1]);
// }

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


class Solution {
  public:
    int getLongestRepeatinSubsequence(string A, string B) {
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

                if(A[i-1] == B[j-1] && i != j){
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