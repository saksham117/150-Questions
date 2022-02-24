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

// Brute force is to linearly iterate over this array and find if its a single element or not
// Or Take XOR of all the numbers in the array. XOR of a and a is 0.
// So only the element which appears once would be non zero and that will be our answer

// Optimized approach
// When the single element occurs, then all the elements, after the single element,occuring in pairs have their second element 
// at even index
// and before that break point, 2nd occurence of elements in pairs will always be at odd index.

// 0 1 2 3 4 5 6 7 8
// 1 1 2 3 3 4 4 8 8 

// So below is the implementation for the same


int singleNonDuplicate(vector<int>& nums) {

        int low = 0; 
        int high = nums.size() - 2; // high will be nums.size() -2 and not -1
        // this also takes care of the case when the single element is the last element of the array

        while(low <= high) {

            int mid = (low + high) >> 1; // right shift by 1 or divide by 2

            // we are checking if we are before break point
            // xor by 1 of even number gives odd number just ahead of it
            // xor by 1 of odd number gives even number just before it
            // so with these we are basically chechcking the first half
            if(nums[mid] == nums[mid^1]) {
                low = mid + 1; // so now go to right
            } 
            else {
                high = mid - 1; // else go to left
            }
        }
        return nums[low]; // after loop terminates, low will point to the single element
    }