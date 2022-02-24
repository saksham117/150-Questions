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

// https://leetcode.com/problems/sort-an-array/

class Solution {
public:
    void helper(vector<int>& nums, int index, int size){
        if(index == size - 1){
            return;
        }
        
        if(nums[index] > nums[index+1]){
            swap(nums[index], nums[index + 1]);
            helper(nums, index+1,size);
        }
        
        return;
        
        
    }
    
    
    void func(vector<int>& nums, int index, int size){
        
        if(index == size - 1){
            return;
        }
        
        func(nums, index + 1, size);
        
        if(nums[index] > nums[index+1]){
            helper(nums,index,size);
        }
        
        return;
    }
    
    vector<int> sortArray(vector<int>& nums) {
        
        int index = 0;
        int n = nums.size();
        
        func(nums,index,n);
        return nums;
    }
};