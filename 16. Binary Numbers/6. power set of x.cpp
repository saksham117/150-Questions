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
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> output; // to store output
        
        int n = nums.size(); // number of elements in the array
//         power set will have elements = 2^n - 1
//         as for every ith location (i < n) I can choose whether to include element or not
        
//         start an outer for loop, where I goes from 0 to 2^n -1
//         2^n -1 can be written as 1 << n - 1 (1 left shifted n times minus 1)
        
        for(int i = 0; i <= (1<<n) - 1; i++){
            vector<int> perm; // one possible permutation
//             now start a for loop which checks for bit position from 0 to n-1
            for(int j = 0; j < n; j++){
                if(i & (1<<j)){ // if the jth bit of my ith term(where i gos from 0 to 2^n-1)
//                     is set, then include the value at jth index in nums
                    perm.push_back(nums[j]);
                }
            }
            
            output.push_back(perm);
        }
        
        return output;
        
        
    }
};