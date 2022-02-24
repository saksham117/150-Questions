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

// Brute Force:
// Take 2 for loops and locate elements. O(N^2) solution

// Optimal
// // Another approach but that would take NLOGN time is
// Sort the array 
// take a left pointer and take a right pointer and search for possible sum and incrememnnt / 
// decrement pointers depending on the state


// Optimal 2: Hashmap

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans; 
        unordered_map<int, int> mpp; 
        for(int i = 0;i<nums.size();i++) {
            if(mpp.find(target - nums[i]) != mpp.end()) {
                ans.push_back(mpp[target-nums[i]]); 
                ans.push_back(i); 
                return ans; 
            }
            mpp[nums[i]] = i; 
        }
        return ans; 
    }
};

