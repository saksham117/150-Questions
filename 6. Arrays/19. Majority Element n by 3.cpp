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

// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

// Brute force approach
// - Use a hashmap or even more brute, pick an element and check for all other(O(N^2)) approach

// Optimized
// So we are again going to use Moores Voting Algorithm that we used in previous video, but we are gonna modify it a bit 
// At max, we can have 2 majority elements and at minimum 0

// Algorithm
// We are gonna take 4 variables, 2 element variables and 2 count variables
// num1 and num2 and count1 and count2

// so if nums = [1,1,1,3,3,2,2,2]
// nums1 = -1, nums2 = -1, count1 = 0, count2 = 0

// for(int i = 0; i < nums; i++)
// {
//     if(nums[i] == nums1){
//         count1++;
//     }
//     else if(nums[i] == nums2){
//         count2++;
//     }
//     elseif(count1 == 0){
//         nums1 = nums[i];
//         count1 = 1;
//     }
//     elseif(count2 == 0){
//         nums2 = nums[i];
//         count2 = 1;
//     }
//     else{
//         count1--;
//         count2--;
//     }
// }

// This is the first pass
// Now we need to perform the second pass to check if these elements are actually majority elements or not
// if count of both > floor(n/3), then return both, if only one of them is majority return that
// else return none

// time complexit is O(N)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int element1 = -1;
        int element2 = -1; // might have to changes these intial values to something outside of range of input
        int count1 = 0;
        int count2 = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == element1){
                count1++;
            }
            else if(nums[i] == element2){
                count2++;
            }
            else if(count1 == 0){
                element1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0){
                element2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }


        // second pass 
        vector<int> ans;
        count1 = 0;
        count2 = 0;

        int limit = nums.size()/3;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == element1){
                count1++;
            }

            if(nums[i] == element2){
                count2++;
            }
        }

        if(count1 > limit){
            ans.push_back(element1);
        }

        if(count2 > limit){
            ans.push_back(element2);
        }

        return ans;

        
    }
};