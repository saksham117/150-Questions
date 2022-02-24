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

// based on kadanes algo
// just handling of negative numbers is different
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int global_max = INT_MIN;
        int local_max = 1;
        int local_min = 1;
        
        
        for(int i = 0; i < nums.size(); i++)
        {   
            if(nums[i] < 0)
            {
                swap(local_max, local_min);
            }
            
            local_max = max(local_max*nums[i],nums[i]);
            local_min = min(local_min*nums[i], nums[i]);
            
            if(local_max > global_max)
            {
                global_max = local_max;
            }
        }
        
        return global_max;
            
    }
};