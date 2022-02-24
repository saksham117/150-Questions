#include <iostream>
#include <climits>
using namespace std;


// BETTER APPROACH IS TO SOLVE IT BY KEEPING LCS IN MIND
// APPLY THE MATCHING ALGORITHM
// OUTPUT IS AN INTEGER
// INPUT IS ONE STRING(WE NEED TO GENERATE TWO)
// AND WE ARE ASKED FOR THE LONGEST OF SOMETHING


// SINCE WE ARE ONLY GIVEN ONE STRING, WE CAN GENERATE THE OTHER STRING
// THE OTHER STRING IS THE SORTED STRING OF THE FIRST STRING
// but another things
// remove duplicates from that sorted string too!!

// AND LCS OF THESE TWO WOULD BE THE ANSWER
// leetcode all case passed

class Solution {
public:
    
    int getLongestSubsequence(vector<int>& A, vector<int>& B) {
        // code here

        int n = A.size();
        int m = B.size();

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
    
    
    int lengthOfLIS(vector<int>& A) {
            
        vector<int> B = A;
        sort(B.begin(), B.end());
        vector<int> sortedB;
        sortedB.push_back(B[0]);
        int j = 0;
        
//         removing duplicates
        for(int i = 1; i < B.size(); i++){
            if(sortedB[j] == B[i])
            {
                continue;
            }
            else{
                sortedB.push_back(B[i]);
                j++;
            }
        }
        
        // for(int i = 0; i < sortedB.size(); i++){
        //     cout<<sortedB[i]<<' ';
        // }
        
        return getLongestSubsequence(A, sortedB);
        return 1;
        
        
    }
};




// so this approach is from pep coding
// heres what I do
//  i create a 1-D Dp array
// if arr = 10 22 9 33 21 50 41 60 80 1
// let me define my dp array to be of size n
// now ith element of dp array would tell, what is the longest increasing subsequence uptill this point
// and an additional clause that this susnet should alwasy contain arr[index] at the last

// now the max of this dp array would be our answer
// below code follows this approach
// second for loop is for finding ki kiss subsequence se judd sakta hoon main, and that to only when arr[i] > arr[j]
/* Dynamic Programming C++ implementation
of LIS problem */

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

/* lis() returns the length of the longest
increasing subsequence in arr[] of size n */
int lis(int arr[], int n)
{
	int lis[n];

	lis[0] = 1;

	/* Compute optimized LIS values in
	bottom up manner */
	for (int i = 1; i < n; i++) {
		lis[i] = 1;
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
	}

	// Return maximum value in lis[]
	return *max_element(lis, lis + n);
}

/* Driver program to test above function */
int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Length of lis is %d\n", lis(arr, n));

	return 0;
}


// This first approach is actually better

// Function to find length of longest increasing subsequence
int LIS(int arr[], int i, int n, int prev)
{
	// Base case: nothing is remaining
	if (i == n)
		return 0;

	// case 1: exclude the current element and process the
	// remaining elements
	int excl = LIS(arr, i + 1, n, prev);

	// case 2: include the current element if it is greater
	// than previous element in LIS
	int incl = 0;
	if (arr[i] > prev)
		incl = 1 + LIS(arr, i + 1, n, arr[i]);

	// return maximum of above two choices
	return max(incl, excl);
}

int main()
{
	int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Length of LIS is " << LIS(arr, 0, n, INT_MIN);

	return 0;
}

// memoization

#include <iostream>
#include <climits>
using namespace std;



// Function to find length of longest increasing subsequence
int LIS(int arr[], int i, int n, int prev)
{
	// Base case: nothing is remaining
	if (i == n)
		return 0;

	// case 1: exclude the current element and process the
	// remaining elements
	int excl = LIS(arr, i + 1, n, prev);

	// case 2: include the current element if it is greater
	// than previous element in LIS
	int incl = 0;
	if (arr[i] > prev)
		incl = 1 + LIS(arr, i + 1, n, arr[i]);

	// return maximum of above two choices
	return max(incl, excl);
}

int main()
{
	int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Length of LIS is " << LIS(arr, 0, n, INT_MIN);

	return 0;
}

