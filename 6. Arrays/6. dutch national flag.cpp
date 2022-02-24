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
    void sortColors(vector<int>& nums) {
        
        
    int low = 0;  
    int high = nums.size() - 1;  
    int mid = 0;  
      
    // Iterate till all the elements 
    // are sorted  
    while (mid <= high)  
    {  
        switch (nums[mid])  
        {  
              
            // mid is 0  
        case 0:  
            swap(nums[low++], nums[mid++]);  
            break;  
              
            // mid is 1 .  
        case 1:  
            mid++;  
            break;  
              
            // mid is 2  
        case 2:  
            swap(nums[mid], nums[high--]);  
            break;  
        }  
    }  
        
    }
};