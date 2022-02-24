// // so we shall divide the problem into 3 parts
// 1) problem statement
// 2) Similarity
// 3) Code variation: Initilialization and Code

// We would be given an input array and a sum value
// And we need to find that whether in this array there exists a subset whose sum is equal to the specified sum
// Just return a yes or a no. No need to return the subset

// We did do a separate question in recursion-2, where we found all such subsets and also found those 
// subsets whose sum was equal to this

// // eg
// arr = [2 3 7 8 10]
// sum = 11

// similarity
// we are given an array 
// we were given W, here we are goven sum
// over there we had to choose whether to take an element or not
// / same is over here

// here array will be t[n + 1][sum +1] ; t[6][12]
// array will be of type bool

// array eill be initilaied according to the base case

// if(sum == 0 and n == 0)
// {
// 	return true;
// }

// if(sum == 0)
// {
// 	return true;
// }

// if(n == 0)
// {
// 	return false;
// }

// write recursive code in rough, as it acts as a good refernce point
// and makes it easier to write the iterative code

// when only one array is given, assume it to be the weight array
// and sum is matched with capacity W

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
    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        
        // creating and initializing
        bool** matrix = new bool*[N+1];
        for(int i = 0; i <= N; i++){
            
            matrix[i] = new bool[sum + 1];
            for(int j = 0; j <= sum; j++){

                if(j == 0){
                    matrix[i][j] = true;
                }
                else if(i == 0){
                    matrix[i][j] = false;
                }
                else{
                    matrix[i][j] = -1;
                }
            }
        }

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= sum; j++){

                if(arr[i-1] <= j){

                    matrix[i][j] = matrix[i-1][j - arr[i-1]] || matrix[i-1][j];
                }
                else{
                    matrix[i][j] = matrix[i-1][j];
                }
            }
        }

        return matrix[N][sum];
    }
};