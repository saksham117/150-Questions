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

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

// Naive Approach
// Sort the array and check for consecutiveness

// Optimal Approach
// Lineraly iterate and store all the elements to a hash set 

// Now iterate again and for every arr[i] element, check if arr[i] - 1 exists in the set or not
// if it exists fine, go ahead and do nothing

// if it does not
// start a while loop
// if set elemet to arr[i] and check if element + 1 exists or not 
// if yes increment counter by 1
// and now set elemet to arr[i] + 1, and check for element + 1 again
// repeat this tell element + 1 does not exist

// if it does not exist, jusr exit the while loop and continue iterating and check if we can get a higher count ahead or not 

// So why we check here and not in above case, is because whenever we want to increment count, we want to start from min eleemnt
// in the subsequence

// Time complexity is approx O(N) as unordered_set / unordered_map work in O(1) complexity

// Just implemented the above logic

// /For further details : https://takeuforward.org/data-structure/longest-consecutive-sequence-in-an-array/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0){
            return 0;
        }
        
        unordered_set<int> listOfElements;

        for(int i = 0; i < nums.size(); i++){
            listOfElements.insert(nums[i]);
        }

        int count = 1;
        int maxCount = 1;

        for(int i = 0; i < nums.size(); i++){

            if(listOfElements.find(nums[i] - 1) != listOfElements.end()){
                continue;
            }
            else{
                int element = nums[i];
                while(true){
                    if(listOfElements.find(element + 1) != listOfElements.end()){
                        count += 1;
                        element  = element + 1;
                        continue;
                    }
                    else{
                        break;
                    }
                }

                if(count > maxCount){
                    maxCount = count;
                }

                count = 1;
            }

        }

        return maxCount;
    }
};