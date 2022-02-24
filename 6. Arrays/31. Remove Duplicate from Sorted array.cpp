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

// Naive approach would be to use a hashset(map), to see what all elements have occured so far

// Optimal Approach
// i coded it myself

// basically took 2 pointers
// 1 to iterate over the array
// and 2nd to keep a track of the index where the new unique element needs to be inserted

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        // base case
        if(nums.size() == 0){
            return 0;
        }
        
        // two pointers. k is length of array to be returned
        int k = 1;
        int j = 1; // j is index where we will place next unique element
        
        for(int i = 1; i < nums.size(); i++){
            // if elemenst are not same, do this
            if(nums[i] != nums[i-1]){
                nums[j] = nums[i];
                j++;
                k+=1;
            }
        }
        
        return k;
    }
};