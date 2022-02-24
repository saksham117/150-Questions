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

// a very slight modification of the previous question

class Solution
{
public:
    void helper(vector<int>& nums, int index, int n, vector<int>& ans, int sum){
        
        if(index == n){
            ans.push_back(sum);
            return;
        }
        
        sum += nums[index];
        helper(nums, index + 1, n, ans, sum);
        sum -= nums[index];
        helper(nums, index + 1, n, ans,sum);
        return;
        
    }
    
    vector<int> subsetSums(vector<int> nums, int n)
    {
        // Write Your Code here
        int index = 0;
        
        
        vector<int> ans;
        int sum = 0;;
        
        helper(nums,index,n,ans,sum);
        return ans;
        
    }
};