// now the quesyion at hand is to print out the scs
// scs is the Shortes common supersequence

// Input: str1 = "abac", str2 = "cab"
// Output: "cabac"
// Explanation: 
// str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
// str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
// The answer provided is the shortest such string that satisfies these properties.

// Algorithm
// call lcs first so that the table is generated
// from that table we shall derive the answer

// now once the table is generetaed do the following steps
// to print and store the lcs

// int i = m; // string 1
// int j = n; // string 2

// string s = "";


// while (i > 0 && j > 0)
// {
// 	if(a[i-1] == b[j-1]) // this part remains the same as we need to include common elements only once
// 	{
// 		s.push_back(a[i-1]);
// 		i--;
// 		j--;
// 	}
// 	else
// 	{
// 		if(t[i][j-1] > t[i-1][j]) // in case of uncommon elements, we shall move in the direction of maximim element 
//                                   // but at the same time store that element whose index we are reducing
// this is because this e;ement is not part of lcs, and when we do say j--, we will be reducing our string of focus
// so that we do not loose this element, and it becomes a part of our scs, we first push that element and then reduce j (or i, if its the other case)
// 		{
// 			s.push_back(b[j-1]);
// 			j--;
// 		}
// 		else
// 		{	
// 			s.push_back(a[i-1]);
// 			i--;
// 		}
// 	}


// }

// // but here we cant stop at this point
// // we need to keep on adding the element till both become empty becasue it is supersequence
// // If Y reaches its end, put remaining characters of X in the result string 
//     while (i > 0) 
//     { 
//         s.push_back(a[i - 1]); 
//         i--,; 
//     } 
  
//   // If X reaches its end, put remaining characters of Y in the result string 
//     while (j > 0) 
//     { 
//         s.push_back(b[j - 1]); 
//         j--; 
//     } 

// reverse(s.begin(), s.end());


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
    string shortestCommonSupersequence(string A, string B) {
        
        // code for creating lcs table till line 115
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

        // intializing the two indices to last element of dp matrix
        int i = n;
        int j = m;
        string s = "";

        while(i > 0 && j > 0){
            if(A[i-1] == B[j-1]){
                s.push_back(A[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                s.push_back(A[i-1]);
                i--;
            }
            else{
                s.push_back(B[j-1]);
                j--;
            }
        }

        for(; i > 0; i--){
            s.push_back(A[i-1]);
        }

        for(; j > 0; j--){
            s.push_back(B[j-1]);
        }

        reverse(s.begin(), s.end());
        return s;

    }
};