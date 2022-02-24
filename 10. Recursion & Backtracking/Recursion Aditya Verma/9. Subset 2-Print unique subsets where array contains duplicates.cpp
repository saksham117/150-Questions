// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

// Solution
// 1) Generate all subsets the convemtional way. Also maintain a set
// 2) Only send that subset to final result vector, if that particular subset is not part of the set 

// However this is a brute force approach
// Moreover inserting elements into the stack will result in additional time of mlogm where m = 2^n
// Space complexoity will also increase as we are using additonal set

// So now we need to optimize the recursion itself 

// Here at each step we will think that we are picking up a list of len 0, then 1, then 2 and so on 
// also when we are at a new level, we pick up that index irrespective if it has already occured or not 
// but if after that index, there are more duplicates, then we ignore them  

// so we will be having function call where one param will be index and the other will be a ds where we are storing our results
// and index will range from i = 0 to to i = n-1, but ensuring we do not pick duplicates 
// time complxity will be 2^n *(n) this additional n for copying the subset to the vector<vector<int>> ans 

// very elegant approach
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
    void helper(vector<int>& nums, int index, vector<int> subset, vector<vector<int>>& ans){
        
        ans.push_back(subset); // each subset on each call will represent a possible subset of nums
        
//         starting from that index, generate all the possible unique subsets
        for(int i = index; i < nums.size(); i++){
            
//             if item is duplicate and current i is not index
            if(i != index && nums[i] == nums[i-1]){
                continue;
            }
            
            subset.push_back(nums[i]);
            helper(nums, i+1,subset,ans);
            subset.pop_back();

        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int> subset; // ds representing a subset
        vector<vector<int>> ans; //ds where all unique subsets will be stored 
        
        sort(nums.begin(), nums.end());
        int index = 0;
        helper(nums,index,subset,ans);
        return ans;
    }
};

