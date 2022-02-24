// you are given an array and you need to find the number of subsets in the array whose sum is equal to the given sum
// again we will take a matrix of size t[n + 1][sum + 1]


// so again inittialiaztion would be pretty similar to what we have done earlier
// insteaed of tru we shall have 1, and instead of false we will have zero

// THIS APPRAOCH ONLY WORKS FOR POSITIVE INTEGRES (0 NOT INCLUDED)
// IF 0 COMES, WE HAVE TO ACTUALLY CALCULATE ALL THE SUBSETS VIA RECURSION AND RETURN THAT COUNT


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
    int perfectSum(int arr[], int N, int sum){
        // code here 
        
        // creating and initializing
        int** matrix = new int*[N+1];
        for(int i = 0; i <= N; i++){
            
            matrix[i] = new int[sum + 1];
            for(int j = 0; j <= sum; j++){

                if(j == 0){
                    matrix[i][j] = 1;
                }
                else if(i == 0){
                    matrix[i][j] = 0;
                }
                else{
                    matrix[i][j] = 0;
                }
            }
        }

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= sum; j++){

                if(arr[i-1] <= j){

                    matrix[i][j] = matrix[i-1][j - arr[i-1]] + matrix[i-1][j];
                }
                else{
                    matrix[i][j] = matrix[i-1][j];
                }
            }
        }

        return matrix[N][sum];
    }
};


