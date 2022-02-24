// We will be given an array, which is unsorted
// say [5,10,20,15]
// and we have to output the index of the peak element
// peak element should be greater than both of its neighbours
// so here answer is index 2

// another array, array is [10,20,15,2,23,90,67]
// 2 peak elements at index 1 and index 5

// We need to return index of any peak element, or -1 if no peak element

// BRUTE FORCE
// O(N) pass and for every element check i-1 and i+1 element

// Binary Search on Answer Approach
// Go to mid element and check for its neighbours
// if greater than both, return that index

// Else we need t  go either left or right
// Now how to decide that??

// If its not the peak element, go the side which offers more promise
// that is go to the larger of its 2 neighbour
// there is bound to be atleast one neighbour in that side because of the nature of the problem and pattern we are looking for 

// try out different arrays and you shall see why

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

// leetcode problem: https://leetcode.com/problems/find-peak-element/submissions/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low)/2;

            bool left = true;
            bool right = true;

            if(mid-1 >= 0 && nums[mid] <= nums[mid-1]){
                left = false;
            }

            if(mid+1 < nums.size() && nums[mid] <= nums[mid+1]){
                right = false;
            }

            if(left && right){
                return mid;
            }
            else{
                if(mid - 1 < 0){
                    low = mid + 1;
                }
                else if(mid + 1 >= nums.size())
                {
                    high = mid - 1;
                }
                else if(nums[mid - 1] > nums[mid]){
                    high = mid -1;
                }
                else{
                    low = mid + 1;
                }

            }
        }

        return -1;
    }
};


