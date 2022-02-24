// Matrix Chain Multiplication using Recursion
//  Given a sequence of matrices, find the most efficient way to multiply these matrices together. 
//  The problem is not actually to  perform the multiplications, 
//  but merely to decide in which order to perform the multiplications. 


// we shall be given an array
// which will represent dimensions a a few matrices
// eg A1, A2, A3, A4
// and we need to multilply them, that is A1*A2*A3*A4
// such that the cost is minimum (no of multiplications is minimum)
// so if we are given two matrices, suppose axb and cxd

// then first condition should be that b = c
// and the matrix after multiplication would be axd

// so the cost is defined as the total no of multiplications that will happen
// and that is equal to a x b x d (take an example and you will agree)
// so if matrices are (2,3) and (3,6)
// matrices will be 2X3X6 = 36

/// in the array that we specified, the dimnesions of the matrices will be stored

// so the question is to see that in all the ways in which we can multiply these, what will result in minimum cost
// like ((A1*A2)*A3)*A4 OR (A1*A2)*(A3*A4) OR (A1*(A2*A3))*A4

// SO if array is 40 20 30 40 30 
// if size of array is n (5),
// then matrices given to us would be n-1(4)
// with dimesnions 40,20 : 20,30 : 30,40 : 40,30

// order will remain same, ki A1*A2*A3*A4, BAS BRACKEST CHANGE KARTE REHNE HAIN

// Ai = arr[i-1] X arr[i] // for dimensions

// so lets solve it
// this question os of mcm category, coz one by one we need to figure out different positions of k, 
// and set a starting index and an ending index i,j

// so we shall set i to 1 and j to n-1 (if n = 5, i = 1, j = 4)
// you can see this by taking an example, and we chose them such becauase Ai = arr[i-1] X arr[i] (ir edge case are 1 and n-1)

// so this is the function call


// 1) find i and j starting values
// 2) figure out base condition
// 3) move k from i to j
// 4) calculate ans from temporary answer


int solve(int arr[], int i, int j)
{
	if( i >= j) // coz i == j will represent array of size 1, and even that does not make sense over here
	{
		return 0;
	}

	int min_ans = INT_MAX;

	for(int k = i; k < j; k++)
	{
		// the explanantion of how i am going to do this i given in the picyure in word doc
		// could not explain it in words

		int tempans = solve(arr, i, k) + solve(arr, k+1,j) + (arr[i-1] * arr[k] * arr[j] );
		// / so basically all the magic is done by recursion
		// first solve brings the cost of multiplication of MATRICES FROM I TO K
		// NEXT SOLVE BRINGS COST OF MATROCES FROM K+1 TO J
		// FINAL COMPUTATION GIVES US THE ANSWER OF COST OF MULTIPLYING THE RESULTANT TWO MATRICES FROM THE FIRST 
        // TWO SOLVE QUESTIONS
		// TAKE AN EXAMPLE TO UNDERSTAND THIS AS WELL AS SEE THE SNIP I HAVE TAKEN

		if(tempans < min_ans)
		{
			min_ans = tempans;
		}
	}

	return min_ans;

}

// MEMOIZATION

// SO AGAIN WE SHALL MAKE USE OF A TABET 
// ISKI DIMESNIOSN WOULD DEPEND ON THE VALUES WHICH ARE CHANGING
// SO I AND J ARE CHANGING
// SO IF N IS THE SIZE OF THE ARRAY, THEN WE SHALL FORM A MATRIX T OF SIZE T[N][N]
// OR T[N+1][N+1] WILL ALSO WORK. ITNI BT NAHI HAI

// INITILIZAE THE MATRIX WITH -1 


// while coding
// to figure out the indices and the function calss as well as the final multiplication after function callss
// take an example and place the indices

// 40 20 30 10 30
//    i   k    j

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

// recursive
class Solution{
public:
    int helper(int arr[], int i, int j){

        if(i >= j){
            return 0;
        }

        int ans = INT_MAX;

        for(int k = i; k < j; k++){

            int tempAns = helper(arr,i,k) + helper(arr,k+1,j) + (arr[i-1] * arr[k] * arr[j]);

            if(tempAns < ans){
                ans = tempAns;
            }
        }

        return ans;

    }

    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int i = 1;
        int j = N-1;
        return helper(arr,i,j);
    }
};

// memoized
class Solution{
public:
    int helper(int arr[], int i, int j, int** matrix){

        if(i >= j){
            return 0;
        }

        if(matrix[i][j] != -1){
            return matrix[i][j];
        }

        int ans = INT_MAX;

        for(int k = i; k < j; k++){

            int tempAns = helper(arr,i,k, matrix) + helper(arr,k+1,j, matrix) + (arr[i-1] * arr[k] * arr[j]);

            if(tempAns < ans){
                ans = tempAns;
            }
        }

        matrix[i][j] = ans;
        return matrix[i][j];

    }

    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int i = 1;
        int j = N-1;
        
        int **matrix = new int*[N+1];
        for(int i = 0; i <= N; i++){
            matrix[i] = new int[N+1];

            for(int j = 0; j <= N; j++){
                matrix[i][j] = -1;
            }
        }

        return helper(arr,i,j,matrix);
    }
};