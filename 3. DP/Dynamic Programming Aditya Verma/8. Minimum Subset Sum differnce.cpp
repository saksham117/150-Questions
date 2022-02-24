// we are given an array and we need to divide it into two subsets such that the difference between their sums should be minimun
// s1- s2 should be minimum
// eg array is {1, 6 , 11, 5}
// output is 1, beciz the two aarays are {1,6,5} and {11}

// this is also quite similar to equal sum subset problem
// let the total sum of array be range
// then if sum of partition 1 is s1, then sum of other array would be range - s1
// so problem gets reduced to what is the best value of s1 we can find to minimize the equation
// s2 - s1 or 
// (range - s1) - s1 or
//  (range) - 2s1

// to ensure that the above value is note negtaive, we ensure that the s1 does not get bigger than range/2
// also the ideal minimum will be when s1 = s2 or s1 = range/2
// if that is not the case, we check for all other possible values for s1, for which this is true
// greater the value of s1, smaller will be the differnce 

// also it would depend on the array, that what values s1 can take which are smaller than range/2

// so the problem reduces to whether that sum exists in the array or not (T/F)
// so for the abive question
// range is 23
// s1 can have maximum value range/2 = 23/2 = 11
// so we shall check all value from 0 to max value of s1
// and whatevver value we get as maximum would be the answer
// we can store all these results in a bool vector
// and the highest index for which sum turns out to be true,
// would be the sum of s1 and differnce would be range - 2*s1


// but this would involve repaeted calculation
// contrary to this carefully observe the table that is from dp
// if arr = {1,2,7} and sum = 10
// t woulb be [4][11]
// the first row tells that on including the first element, would sum of 0,1,2,3......10 be possible or not
// the second row tells that on including the first two element, would sum of 0,1,2,3......10 be possible or not
// the third row tells that on including all three element, would sum of 0,1,2,3......10 be possible or not

// so this third row is the asnswer we are looking for
// in the third row, the highest coulmn which has true, will be s1


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
    int minDifference(int arr[], int n){
        // code here 

        int sum_a = 0;
        
        for(int i = 0; i < n; i++){
            sum_a += arr[i];
        }

        int sum1 = (int)sum_a/2;

        // creating and initializing
        bool** matrix = new bool*[n+1];
        for(int i = 0; i <= n; i++){
            
            matrix[i] = new bool[sum1 + 1];
            for(int j = 0; j <= sum1; j++){

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

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum1; j++){

                if(arr[i-1] <= j){

                    matrix[i][j] = matrix[i-1][j - arr[i-1]] || matrix[i-1][j];
                }
                else{
                    matrix[i][j] = matrix[i-1][j];
                }
            }
        }

        int s1;

        for(int j = sum1; j >= 0; j--){
            if(matrix[n][j] == true){
                s1 = j;
                break;
            }
        }

        return sum_a - 2*s1;

        
    }
};

// Done on both gfg and interviewbit
