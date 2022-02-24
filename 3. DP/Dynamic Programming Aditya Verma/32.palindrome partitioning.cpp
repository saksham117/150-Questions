// as input, we shall be provided a string
// say nitik
// so we would divide this thing into lets say 3 parts, by making two partitions and by doing so 
// the three  strings so formed should be palindromes
// so if we didivide it like 'n' , 'iti', 'k'
// then we would have three strings which are all palindromes
// so we need to return the minimum number of partitions
// in the worst case, what we can do is that for a string of length n, make n-1 partitinons, that is divide at each letter
// and each letter would infact be a palindrome
// so that is the maximum count
// we need to find the minimum

// now how is his related to mcm
// first we need to traverse the string to find out where we need to make the partitions
// we need an 'i' which is the left most index and a 'j' which is the right most index
// then in between those i and j, we need to make a partiton somewhere where the answer is minimum
// so that will be represented by k

// so now let us see the 4 stes of mcm
// 1 find out the value for i and j
// find the base condition
// then move k
// then apply a function to find the final answer

// i will be passed as zero and j as string length -1


// int solve(string s, int i, int j)
// {
// 	// base condition

// 	if( i >= j) // i > j represent an empty string and i == j represents a single alphabet
// 				// in both cases, zero partitions are required so we shall return 0
// 	{
// 		return 0;
// 	}

// 	// then we would have to make another function, which checks that whether the string given from i to j is a palindrome or not

// 	if (isPalindrome(string s, i, j))
// 	{
// 		return 0;
// 	}

// 	int ans = INT_MAX:

// 	for(int k = i; k < j; k++)
// 	{
// 		int tempans = solve(s, i, k) + solve(s, k+1, j) + 1;

// 		if(tempans < ans)
// 		{
// 			ans = tempans;
// 		}
// 	}

// 	return ans;

// }

// // MEMOIZATION
// // SO THE TABLE WILL BE FORMED BASED ON THE VALUES OF I AND J
// // THEY SHALL VARY FROM SIZE 0 TO LENGTH OF STRING
// // SO WE CAN TAKE T AS T[N+1][N+1]

// int t[1001][1001]

// memset(t ,-1, sizeof(t)) // set this in main


// int solve(string s, int i, int j)
// {
// 	// base condition

// 	if( i >= j) // i > j represent an empty string and i == j represents a single alphabet
// 				// in both cases, zero partitions are required so we shall return 0
// 	{
// 		return 0;
// 	}

// 	if(t[i][j] != -1)
// 	{
// 		return t[i][j];
// 	}

// 	// then we would have to make another function, which checks that whether the string given from i to j is a palindrome or not

// 	if (isPalindrome(string s, i, j))
// 	{
// 		return 0;
// 	}

// 	int ans = INT_MAX:

// 	for(int k = i; k < j; k++)
// 	{
// 		int tempans = solve(s, i, k) + solve(s, k+1, j) + 1;

// 		if(tempans < ans)
// 		{
// 			ans = tempans;
// 		}
// 	}

// 	t[i][j] = ans;
// 	return t[i][j];


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

// memoized + recursive code
// also note that passing string as reference and not as value can also save time (as then compiler wont have to create
// multiple copies of the same string over and over again) 
class Solution {
public:

    bool isPalindrome(string &s, int i, int j){

        while(i < j){
            if(s[i] != s[j]){
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

    int helper(string &s, int i, int j,int** matrix){

        if(i >= j){
            return 0;
        }

        if(matrix[i][j] != -1){
            return matrix[i][j];
        }

        if(isPalindrome(s,i,j)){
            return 0;
        }

        int minAns = INT_MAX;

        for(int k = i; k < j; k++){

            int ans = helper(s, i, k, matrix) + helper(s,k+1,j, matrix) + 1;

            if(ans < minAns){
                minAns = ans;
            }
        }

        matrix[i][j] = minAns;
        return matrix[i][j];
    }

    int minCut(string s) {
        
        int i = 0;
        int j = s.length() - 1; 
        int N = s.length();

        int **matrix = new int*[N+1];
        for(int a = 0; a <= N; a++){
            matrix[a] = new int[N+1];

            for(int b = 0; b <= N; b++){
                matrix[a][b] = -1;
            }
        }

        return helper(s,i,j, matrix);
    }
};

// THIS CODE CAN BE FURTHER OPTIMIZED AS IT FAILS CERTAIN CASES IN LEETCODE
// basically earlier we were checking whether only palindrom from i to j is checked or not
// if it failed, we further calculated
// now we are also checking of its subproblems, ie i to k and k+1 to j are already checked or not 

// this still fails, so now we will also create a table for checking if we have already cheched for palindrom property or not.
class Solution {
public:

    bool isPalindrome(string &s, int i, int j){

        while(i < j){
            if(s[i] != s[j]){
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

    int helper(string &s, int i, int j,int** matrix){

        if(i >= j){
            return 0;
        }

        if(matrix[i][j] != -1){
            return matrix[i][j];
        }

        if(isPalindrome(s,i,j)){
            return 0;
        }

        int minAns = INT_MAX;

        for(int k = i; k < j; k++){

            int leftAns = matrix[i][k] != -1 ? matrix[i][k] : helper(s, i, k, matrix);
            int rightAns = matrix[k+1][j] != -1 ? matrix[k+1][j] : helper(s, k+1, j, matrix);

            int ans =  leftAns + rightAns + 1;

            if(ans < minAns){
                minAns = ans;
            }
        }

        matrix[i][j] = minAns;
        return matrix[i][j];
    }

    int minCut(string s) {
        
        int i = 0;
        int j = s.length() - 1; 
        int N = s.length();

        int **matrix = new int*[N+1];
        for(int a = 0; a <= N; a++){
            matrix[a] = new int[N+1];

            for(int b = 0; b <= N; b++){
                matrix[a][b] = -1;
            }
        }

        return helper(s,i,j, matrix);
    }
};



// created a dp matrix even for isPalindrome func
class Solution {
public:

    bool isPalindrome(string &s, int i, int j, int **matrixPalindrome){

        if(matrixPalindrome[i][j] != -1){
            return matrixPalindrome[i][j];
        }

        while(i < j){
            if(s[i] != s[j]){
                matrixPalindrome[i][j] = 0;
                return matrixPalindrome[i][j];
            }

            i++;
            j--;
        }

        matrixPalindrome[i][j] = 1;
        return matrixPalindrome[i][j];
    }

    int helper(string &s, int i, int j,int** matrix, int **matrixPalindrome){

        if(i >= j){
            return 0;
        }

        if(matrix[i][j] != -1){
            return matrix[i][j];
        }

        if(isPalindrome(s,i,j, matrixPalindrome)){
            return 0;
        }

        int minAns = INT_MAX;

        for(int k = i; k < j; k++){

            int leftAns = matrix[i][k] != -1 ? matrix[i][k] : helper(s, i, k, matrix, matrixPalindrome);
            int rightAns = matrix[k+1][j] != -1 ? matrix[k+1][j] : helper(s, k+1, j, matrix, matrixPalindrome);

            int ans =  leftAns + rightAns + 1;

            if(ans < minAns){
                minAns = ans;
            }
        }

        matrix[i][j] = minAns;
        return matrix[i][j];
    }

    int minCut(string s) {
        
        int i = 0;
        int j = s.length() - 1; 
        int N = s.length();

        int **matrix = new int*[N+1];
        for(int a = 0; a <= N; a++){
            matrix[a] = new int[N+1];

            for(int b = 0; b <= N; b++){
                matrix[a][b] = -1;
            }
        }

        int **matrixPalindrome = new int*[N+1];
        for(int a = 0; a <= N; a++){
            matrixPalindrome[a] = new int[N+1];

            for(int b = 0; b <= N; b++){
                matrixPalindrome[a][b] = -1;
            }
        }

        return helper(s,i,j, matrix, matrixPalindrome);
    }
};