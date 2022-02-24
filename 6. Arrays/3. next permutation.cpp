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
    void nextPermutation(vector<int>& nums) {
        
        int i = nums.size()-1;
        while(i >= 1)
        {  
            if(nums[i-1] >= nums[i])
            {   
                i--;
                continue;
            }
            else
            {
                break;
            }
        }
        
        if(i == 0)
        {   
            reverse(nums.begin() + i, nums.end());
            return;
        }
        
        int j = i - 1;
        int val = nums[j];

        reverse(nums.begin() + i, nums.end());

        while(i < nums.size())
        {
            if(val < nums[i])
            {
                swap(nums[j],nums[i]);
                break;
            }
            i++;
        }
        
        
    }
};

// eg [1,3,2]
// op [2,1,3]