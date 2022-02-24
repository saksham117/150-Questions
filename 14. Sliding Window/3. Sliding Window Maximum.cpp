#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<set>
#include<map>

using namespace std;

// Naive solution: Traverse all k sized windows which are possible one by one using a for loop
// for(int i = 0; i <= n-k; i++)
// for(int j = i; j < i + k; j++){
    // find max amongst the three elements 
// }
// Time O(NXK) ~ Almost N^2 

// We are next going to try nge or the Next Greater Element Approach
// dequeue is nothing but a dll being implemented and we are gonna use that 
// dequeue allows you to push and pop from both back and front in O(1) time 
// We will start from the left and store elements in a decresing fashion
// example, arr = 1,3,-1,-3,5,3,6,7
// index  =       0,1,2,3,4,5,6,7,8

// k = 3

// so this is what we will do 
// 1) start inserting elements from left
//      intially dequeue will be empty, so insert it at back
//      so our dequeue will have 1 at the end

// 2) then go to next element
// since we are storing thme in decresing order
// if current element is smaller than element at dequeue last
//      insert it and end
// else
//      keep on popping till a greater element is found or dequeue becomes empty, and then push_back

// 3) also at the very start check, if the deque is not empty and element at the very start belongs to window or not 

// 4) push the element at front of dequeue into answer after every i >= k - 1


// Striver Solution
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // storws the index
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) {
            // for removing the element not a part of the window
            if (!dq.empty() && dq.front() == i-k) dq.pop_front();
            
            // finding the right location to insert the indixe
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            
            dq.push_back(i);
            // return the front for every i >= k -1 
            if (i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};



// using a multiset but might not work in interview
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        multiset<int> s; 

        for(int i = 0; i < k; i++){
            s.insert(nums[i]);
        }
        

        int max_element = *(s.rbegin());
        output.push_back(max_element);


        for(int i = k; i < nums.size(); i++){
            s.erase(s.find(nums[i-k]));
            s.insert(nums[i]);
            int max_element = *(s.rbegin());
            output.push_back(max_element);
            
        }

        return output;
    }
};