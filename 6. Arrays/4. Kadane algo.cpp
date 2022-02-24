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
    int maxSubArray(vector<int>& nums) {
        int global_sum = INT_MIN;
        int local_sum = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            local_sum = max(local_sum + nums[i], nums[i]);
            if(local_sum > global_sum){
                global_sum = local_sum;
            }
        }

        return global_sum;
    }
};