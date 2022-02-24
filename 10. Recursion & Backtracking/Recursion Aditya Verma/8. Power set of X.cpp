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

// one way is to do it using bits and checking if ith bit is set or not 
// this technique striver told and is very elegant
// time complexity is O(2^n * N)
// this is not the best appraoch
// recursive approach is better in this case

// let me today try the recursive approach 
// coded it myself
// basically the crux is that, shold I include this element or should I not include this element

// calculatins space and time complexity (told by striver)
// https://www.youtube.com/watch?v=rYkfBRtMJr8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=10
// Basically for every index I have 2 ways, either to include the element or to not include the element 
// so this way I will generate a tree of size 2^n and trvaersing that will take 2^n time 
class Solution {
public:
    void helper(vector<int>& nums, int index, int n, vector<vector<int>>& ans, vector<int> subset){
        
        if(index == n){
            ans.push_back(subset);
            return;
        }
        
        subset.push_back(nums[index]);
        helper(nums, index + 1, n, ans, subset);
        subset.pop_back();
        helper(nums, index + 1, n, ans,subset);
        return;
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int index = 0;
        int n = nums.size();
        
        vector<vector<int>> ans;
        vector<int> subset;
        
        helper(nums,index,n,ans,subset);
        return ans;
        
    }
};