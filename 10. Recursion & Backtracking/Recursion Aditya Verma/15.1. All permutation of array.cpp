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
    void helper(vector<int>& nums, vector<int> permutation, unordered_set<int> hashSet,           vector<vector<int>>& ans){
        
        if(permutation.size() == nums.size()){
            ans.push_back(permutation);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            
            if(hashSet.find(nums[i]) != hashSet.end()){
                continue;
            }
            
            hashSet.insert(nums[i]);
            permutation.push_back(nums[i]);
            helper(nums,permutation,hashSet,ans);
            permutation.pop_back();
            hashSet.erase(nums[i]);
        }
        
        return;
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        unordered_set<int> hashSet;
        vector<int> permutation;
        vector<vector<int>> ans;
        
        helper(nums, permutation, hashSet, ans);
        return ans;
        
    }
};