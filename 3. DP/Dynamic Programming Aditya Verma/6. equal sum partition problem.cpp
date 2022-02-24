// given an array, can we divide it into two subsets, such that their sum is gonna be equal
// output true or false

// eg array is {1, 5 ,11, 5 }
// so it can be partitioned into two {1,5,5} and {11}

// so if we observe carefully, this is indead quite similar to the subset sum problem
// so if a equal partion does exist, then sum of either of the subsets would be total sum of array /2
// so in the above example, total sum is 22. and sum of each equal subset is 11
// so the problem reduces to whether there exists a subset whose sum is 11

// amnother thing that we can conclude is that the total sum of the array should be even
// if it is not even, then there is no possible way to divdie the array into two equal halves

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
    bool subsetSum(vector<int>& arr, int n, int sum){

    bool** t = new bool*[n+1];
    for(int i = 0; i <= n; i++){
        t[i] = new bool[sum+1];
    }

    for(int i = 0; i <= sum; i++)
    {
        t[0][i] = false;
    }

    for(int i = 0; i <= n; i++)
    {
        t[i][0] = false;
    }

    t[0][0] = true;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){

            if(arr[i-1] <= j)
            {
                bool ans = (t[i-1][j - arr[i-1]]) || (t[i-1][j]);
                t[i][j] = ans;
              
            }
            else{
                bool ans = t[i-1][j];
                t[i][j] = ans;
            }
        }
    }

    return t[n][sum];
}
    
    bool canPartition(vector<int>& nums) {
        
        int N = nums.size();
        int sum = 0;
        for(int i = 0; i < N; i++)
        {
            sum += nums[i];
        }
        
        if(sum%2 == 0)
        {
            return subsetSum(nums, N, sum/2);
            
        }
        else
        {
            return false;
        }
        
    }
};

// so it is this simple!!!!!!!!!!!