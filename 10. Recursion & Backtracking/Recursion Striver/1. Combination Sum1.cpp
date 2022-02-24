// Nothing but unbounded knapsack
// and since we have to explore all the combinations
// ans aldo maintain those combinations
// we have ti use recrsion
// code could be optimized using memoization (a big could be)
// coded it myslef

// here is the code

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
    
    void helper(vector<int>& candidates, int target, int index, vector<int> combination, 
               vector<vector<int>>& ans){
        
//         base case
        if(index == candidates.size()){
            return;
        }
        
        if(target == 0){
            ans.push_back(combination);
            return;
        }
        
        
        if(candidates[index] <= target){
            
            combination.push_back(candidates[index]);
            helper(candidates, target - candidates[index], index, combination, ans);
            combination.pop_back();
            
            helper(candidates, target, index + 1, combination, ans);
        }
        else{
            helper(candidates, target, index + 1, combination, ans);
        }
        
        return;
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int index = 0;
        vector<int> combination;
        vector<vector<int>> ans;
        
        helper(candidates, target, index, combination, ans);
        
        return ans;
    }
};

// Time complexity
// 2^t*k (t is target and k is average length of the sequece)
// we took t because till target is reached to 0
// we can either pick or not pick the elements 
// the addditional k term is for insertiung the sequence into the ds 
// genrally the interb=viewer does not ask for problems like these 